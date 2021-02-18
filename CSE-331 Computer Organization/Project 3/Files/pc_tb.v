module pc_tb(output testout);

reg [5:0] instruction_count;
reg clock;
wire [31:0] n_instruction;
reg [31:0] a_instructions[24:0];
program_counter_block pc(clock,n_instruction);
initial begin
		$readmemb("/Dersler/CSE331-Computer_Organization/HW4/HW4/instructions.txt", pc.all_instruction);
		clock = 1'b1;
		instruction_count = 24;
	end

always #10 clock = ~clock;

always @(posedge clock) begin
		$monitor("last data: %32b\nnew instruction: %32b\n program counter:%6b\n",pc.all_instruction[23],pc.new_instruction,pc.program_c);
		if(instruction_count == pc.program_c) begin
			$finish;
		end
	end

endmodule
