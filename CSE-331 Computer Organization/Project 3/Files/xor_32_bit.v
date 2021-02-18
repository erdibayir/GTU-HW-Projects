module xor_32_bit(i1,i2,out);

input [31:0] i1,i2;
output [31:0] out;

xor x1(out[0],i1[0],i2[0]);
xor x2(out[1],i1[1],i2[1]);
xor x3(out[2],i1[2],i2[2]);
xor x4(out[3],i1[3],i2[3]);
xor x5(out[4],i1[4],i2[4]);
xor x6(out[5],i1[5],i2[5]);
xor x7(out[6],i1[6],i2[6]);
xor x8(out[7],i1[7],i2[7]);
xor x9(out[8],i1[8],i2[8]);
xor x10(out[9],i1[9],i2[9]);
xor x11(out[10],i1[10],i2[10]);
xor x12(out[11],i1[11],i2[11]);
xor x13(out[12],i1[12],i2[12]);
xor x14(out[13],i1[13],i2[13]);
xor x15(out[14],i1[14],i2[14]);
xor x16(out[15],i1[15],i2[15]);
xor x17(out[16],i1[16],i2[16]);
xor x18(out[17],i1[17],i2[17]);
xor x19(out[18],i1[18],i2[18]);
xor x20(out[19],i1[19],i2[19]);
xor x21(out[20],i1[20],i2[20]);
xor x22(out[21],i1[21],i2[21]);
xor x23(out[22],i1[22],i2[22]);
xor x24(out[23],i1[23],i2[23]);
xor x25(out[24],i1[24],i2[24]);
xor x26(out[25],i1[25],i2[25]);
xor x27(out[26],i1[26],i2[26]);
xor x28(out[27],i1[27],i2[27]);
xor x29(out[28],i1[28],i2[28]);
xor x30(out[29],i1[29],i2[29]);
xor x31(out[30],i1[30],i2[30]);
xor x32(out[31],i1[31],i2[31]);
endmodule

