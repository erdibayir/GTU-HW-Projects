module program_counter_block(clock,new_instruction);
input clock;
output [31:0] new_instruction;
reg [31:0] n_instruction;
reg [5:0] program_c;
reg [31:0] all_instruction[27:0];

initial
	begin
		program_c = 6'b00000;
	end
	assign new_instruction = n_instruction;
	
	always @(posedge clock) begin
		n_instruction = all_instruction[program_c];
		program_c = program_c + 1'b1;
	end
	
endmodule