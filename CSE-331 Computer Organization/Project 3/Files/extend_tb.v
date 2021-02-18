module extend_tb(output testout);

reg [15:0] i1,i2;
wire [31:0] out1, out2;

extend_16_to_32 e0(i1,i1[15],out1);
extend_16_to_32 e1(i2,i2[15],out2);

initial begin
	i1 = 16'b0010100010101010;
	i2 = 16'b1110100010001010;

	$monitor("Unsigned : %16b == %32b\n  Signed : %16b == %32b", i1, out1, i2, out2);
end

endmodule 