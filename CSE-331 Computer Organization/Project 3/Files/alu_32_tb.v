module alu_32_tb(output testout);
	reg [31:0] i1,i2;
	wire [31:0] out;
	reg [2:0] alu_op_select;
	alu_32_bit alu1(i1,i2,alu_op_select,zero_bit,out);
	initial begin
	i1 = 32'd9;
	i2 = 32'd3;
	alu_op_select = 3'b010;
	#10
	i1 = 32'd9;
	i2 = 32'd3;
	alu_op_select = 3'b110;
	#10
	i1 = 32'd9;
	i2 = 32'd3;
	alu_op_select = 3'b000;
	#10
	i1 = 32'd9;
	i2 = 32'd3;
	alu_op_select = 3'b001;
	#10
	i1 = 32'd9;
	i2 = 32'd3;
	alu_op_select = 3'b111;
	end
	
	initial begin	
	$monitor(
	   "input1=%b = %d\ninput2=%b = %d Operation:%b\n   out=%b = %d\n",
		   i1,i1,i2,i2,alu_op_select,out,out);
	end

endmodule