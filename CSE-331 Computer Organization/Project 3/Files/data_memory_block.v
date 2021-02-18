module data_memory_block(address, write_data, mem_write_sg,read_data,clock);

	input [31:0] address, write_data;
	input mem_write_sg, clock;
	output [31:0] read_data;

	reg [31:0] memory [255:0];
	
	assign read_data = memory[address[7:0]];
	always @(posedge clock)
	begin
		if (mem_write_sg == 1'b1)
		begin
			memory[address[7:0]] <= write_data;
			$writememb("/Dersler/CSE331-Computer_Organization/HW4/HW4/memory_data.txt", memory);
		end
	end
endmodule