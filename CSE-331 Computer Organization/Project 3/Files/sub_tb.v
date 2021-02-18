module sub_tb(output testout);
	reg [31:0] i1,i2;
	wire [31:0] out;
	sub_32_bit a1(i1,i2,out);
	
initial begin
	i1 = 32'd19;
	i2 = 32'd13;
	#50
	i1 = 32'd9;
	i2 = 32'd7;
	#50
	i1 = 32'd8;
	i2 = 32'd3;
	#50
	i1 = 32'd5;
	i2 = 32'd5;
	end
initial begin
	$monitor(
	   "input1=%b= %d\ninput2=%b = %d\nout=%b =%d\n",
		   i1,i1,i2,i2,out,out);
	end

endmodule
