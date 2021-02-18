module register_block(clock,read_reg_1,read_reg_2,write_register1,write_register2,read_data_1,read_data_2,
							signal_reg_write,write_data1,write_data2);
	reg [31:0] registers[31:0];
	input [31:0] write_data1,write_data2;
	input [4:0] read_reg_1,read_reg_2,write_register1,write_register2;
	input clock;
	input signal_reg_write;
	output [31:0] read_data_1,read_data_2;
	assign read_data_1 = registers[read_reg_1];
	assign read_data_2 = registers[read_reg_2];
	
	always @(posedge clock)
	begin
		if (signal_reg_write == 1'b1)
		begin
			registers[write_register1] <= write_data1;
			registers[write_register2] <=write_data2;
			$writememb("/Dersler/CSE331-Computer_Organization/HW4/HW4/new_registers.mem", registers);
		end
	end
endmodule
