module mips32_tb(output testout);
reg [4:0] counter;
reg clock;
mips32 mips(clock);
initial begin
		$readmemb("/Dersler/CSE331-Computer_Organization/HW4/HW4/registers.txt", mips.register.registers);
		$readmemb("/Dersler/CSE331-Computer_Organization/HW4/HW4/memory_data.txt", mips.data.memory);
		$readmemb("/Dersler/CSE331-Computer_Organization/HW4/HW4/instructions.txt", mips.pc.all_instruction);
		clock = 1'b1;
		counter = 24;
	end
	always #10 clock = ~clock;
always @(posedge clock) begin
	
		$monitor("Opcode:%2h,Rs:%h Rt:%h Rd:%h immediate:%h regWrite:%1b Alu Control Unit Out:%b RegDst:%b Branch:%b MemWrite:%1b ALUSrc:%1b MemToReg:%b AluOP:%b\nAlu Result:%b Read_data_2:%32b\nRead_data_1:%32b\ndata[0]:%32b\ndata[1]:%32b\ndata[2]:%32b\n Reg[1]=%32b\n Data Read Data:%32b\n Final Data:%32b\n " ,
					mips.instruction[31:26], mips.instruction[25:21],
					mips.instruction[20:16],mips.instruction[15:11], mips.instruction[15:0],
					mips.RegWrite,mips.alu_cu_out,mips.regDst,mips.branch,mips.MemWrite, mips.ALUSrc, mips.MemToReg,
					mips.AluOp,mips.alu_Out,mips.read_data_2,mips.read_data_1,mips.data.memory[0],mips.data.memory[1],mips.data.memory[2]
					,mips.register.registers[1],mips.data_block_read_data,mips.final_data1);
		
			$writememb("/Dersler/CSE331-Computer_Organization/HW4/HW4/new_Registers.txt", mips.register.registers);
			$writememb("/Dersler/CSE331-Computer_Organization/HW4/HW4/new_memory_data.txt", mips.data.memory);
end	

endmodule