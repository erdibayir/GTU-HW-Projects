module extend_16_to_32(i1,sign,out);
	input [15:0] i1;
	input sign;
	output [31:0] out;

	and a0(out[0], i1[0], i1[0]);
	and a1(out[1], i1[1], i1[1]);
	and a2(out[2], i1[2], i1[2]);
	and a3(out[3], i1[3], i1[3]);
	and a4(out[4], i1[4], i1[4]);
	and a5(out[5], i1[5], i1[5]);
	and a6(out[6], i1[6], i1[6]);
	and a7(out[7], i1[7], i1[7]);
	and a8(out[8], i1[8], i1[8]);
	and a9(out[9], i1[9], i1[9]);
	and a10(out[10], i1[10], i1[10]);
	and a11(out[11], i1[11], i1[11]);
	and a12(out[12], i1[12], i1[12]);
	and a13(out[13], i1[13], i1[13]);
	and a14(out[14], i1[14], i1[14]);
	and a15(out[15], i1[15], i1[15]);
	and a16(out[16], i1[15], sign);
	and a17(out[17], i1[15], sign);
	and a18(out[18], i1[15], sign);
	and a19(out[19], i1[15], sign);
	and a20(out[20], i1[15], sign);
	and a21(out[21], i1[15], sign);
	and a22(out[22], i1[15], sign);
	and a23(out[23], i1[15], sign);
	and a24(out[24], i1[15], sign);
	and a25(out[25], i1[15], sign);
	and a26(out[26], i1[15], sign);
	and a27(out[27], i1[15], sign);
	and a28(out[28], i1[15], sign);
	and a29(out[29], i1[15], sign);
	and a30(out[30], i1[15], sign);
	and a31(out[31], i1[15], sign);

endmodule