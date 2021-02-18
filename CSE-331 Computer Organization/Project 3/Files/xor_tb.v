module xor_tb(output testout);
reg [31:0] i1,i2;
	wire [31:0] out;
	xor_32_bit x1(i1,i2,out);
	
initial begin
	i1 = 32'd1120;
	i2 = 32'd8234;
	#50
	i1 = 32'd657;
	i2 = 32'd456;
	#50
	i1 = 32'd0;
	i2 = 32'd3;
	#50
	i1 = 32'd5;
	i2 = 32'd5;
	end
initial begin
	$monitor(
	   "input1=%b\ninput2=%b\n   out=%b\n",
		   i1,i2,out);
	end

endmodule