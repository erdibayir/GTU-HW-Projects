module mux_32_tb(output testout);

reg [31:0] i1,i2;
	wire [31:0] out;
	reg select_b;
	mux_32_bit_2_1 m1(i1,i2,out,select_b);
	
	initial begin 
		i1 = 32'b0000_0100_0100_0001_0000_0000_0000_0000;
		i2 = 32'b0000_0000_0000_0000_0000_0000_1100_0011;
		select_b = 1'b0;
		#50
		i1 = 32'b0000_0100_0100_0001_0000_0000_0110_0101;
		i2 = 32'b0000_0000_0000_0000_0000_0000_1100_0011;
		select_b = 1'b1;
		#50
		i1 = 32'b0000_0100_0100_0001_0000_0000_0110_0101;
		i2 = 32'b0000_0000_0000_0000_0000_0000_1100_0011;
		select_b = 1'b0;
		
	end

initial begin
	$monitor(
	   " input1=%b\n input2=%b Select Bit :%b\n   out=%b",
		   i1,i2,select_b,out);
	end

endmodule