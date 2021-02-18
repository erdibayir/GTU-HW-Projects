module mips32(clock);
input clock;
wire regDst,branch,MemRead,MemToReg,MemWrite,ALUSrc,RegWrite;
wire [1:0] AluOp;
wire [31:0] extended_32_bit;
wire [4:0] reg_dest_out;
wire [31:0] instruction,read_data_1,read_data_2,final_data1,final_data2,alu_mux_input,alu_Out,data_block_read_data;
wire [2:0] alu_cu_out;
wire [31:0] zero_bit;
program_counter_block pc(clock,instruction);
control_unit cu(instruction[31:26],regDst,branch,MemRead,MemToReg,AluOp,MemWrite,ALUSrc,RegWrite);
extend_16_to_32 ext(instruction[15:0],1'b0,extended_32_bit);
mux_5_bit_2_1 mux_5(instruction[20:16],instruction[15:11],reg_dest_out,regDst);

register_block register(clock,instruction[25:21],instruction[20:16],reg_dest_out,5'b00000,read_data_1,read_data_2,RegWrite,final_data1,final_data2);
mux_32_bit_2_1 mux_32_1(read_data_2,extended_32_bit,alu_mux_input,ALUSrc);
alu_control_unit alu_cu(AluOp,instruction[5:0],alu_cu_out);
alu_32_bit alu_32(read_data_1,alu_mux_input,alu_cu_out,zero_bit,alu_Out);
data_memory_block data(alu_Out,read_data_2,MemWrite,data_block_read_data,clock);
mux_32_bit_2_1 mux_32_2(alu_Out,data_block_read_data,final_data1,MemToReg);
endmodule
