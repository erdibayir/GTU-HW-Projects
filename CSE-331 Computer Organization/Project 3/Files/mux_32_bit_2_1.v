module mux_32_bit_2_1(i1,i2,out,select_b);
input [31:0] i1,i2;
input select_b;
output [31:0] out;

mux_1_bit_2_1 m1(i1[0],i2[0],select_b,out[0]);
mux_1_bit_2_1 m2(i1[1],i2[1],select_b,out[1]);
mux_1_bit_2_1 m3(i1[2],i2[2],select_b,out[2]);
mux_1_bit_2_1 m4(i1[3],i2[3],select_b,out[3]);
mux_1_bit_2_1 m5(i1[4],i2[4],select_b,out[4]);
mux_1_bit_2_1 m6(i1[5],i2[5],select_b,out[5]);
mux_1_bit_2_1 m7(i1[6],i2[6],select_b,out[6]);
mux_1_bit_2_1 m8(i1[7],i2[7],select_b,out[7]);
mux_1_bit_2_1 m9(i1[8],i2[8],select_b,out[8]);
mux_1_bit_2_1 m10(i1[9],i2[9],select_b,out[9]);
mux_1_bit_2_1 m11(i1[10],i2[10],select_b,out[10]);
mux_1_bit_2_1 m12(i1[11],i2[11],select_b,out[11]);
mux_1_bit_2_1 m13(i1[12],i2[12],select_b,out[12]);
mux_1_bit_2_1 m14(i1[13],i2[13],select_b,out[13]);
mux_1_bit_2_1 m15(i1[14],i2[14],select_b,out[14]);
mux_1_bit_2_1 m16(i1[15],i2[15],select_b,out[15]);
mux_1_bit_2_1 m17(i1[16],i2[16],select_b,out[16]);
mux_1_bit_2_1 m18(i1[17],i2[17],select_b,out[17]);
mux_1_bit_2_1 m19(i1[18],i2[18],select_b,out[18]);
mux_1_bit_2_1 m20(i1[19],i2[19],select_b,out[19]);
mux_1_bit_2_1 m21(i1[20],i2[20],select_b,out[20]);
mux_1_bit_2_1 m22(i1[21],i2[21],select_b,out[21]);
mux_1_bit_2_1 m23(i1[22],i2[22],select_b,out[22]);
mux_1_bit_2_1 m24(i1[23],i2[23],select_b,out[23]);
mux_1_bit_2_1 m25(i1[24],i2[24],select_b,out[24]);
mux_1_bit_2_1 m26(i1[25],i2[25],select_b,out[25]);
mux_1_bit_2_1 m27(i1[26],i2[26],select_b,out[26]);
mux_1_bit_2_1 m28(i1[27],i2[27],select_b,out[27]);
mux_1_bit_2_1 m29(i1[28],i2[28],select_b,out[28]);
mux_1_bit_2_1 m30(i1[29],i2[29],select_b,out[29]);
mux_1_bit_2_1 m31(i1[30],i2[30],select_b,out[30]);
mux_1_bit_2_1 m32(i1[31],i2[31],select_b,out[31]);

endmodule