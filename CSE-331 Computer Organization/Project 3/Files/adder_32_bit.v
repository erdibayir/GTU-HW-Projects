module adder_32_bit(i1,i2,out);
input [31:0] i1,i2;
output [31:0] out;
wire cout;

full_adder f1(i1[0],i2[0],1'b0,out[0],cout);
full_adder f2(i1[1],i2[1],cout,out[1],cout1);
full_adder f3(i1[2],i2[2],cout1,out[2],cout2);
full_adder f4(i1[3],i2[3],cout2,out[3],cout3);
full_adder f5(i1[4],i2[4],cout3,out[4],cout4);
full_adder f6(i1[5],i2[5],cout4,out[5],cout5);
full_adder f7(i1[6],i2[6],cout5,out[6],cout6);
full_adder f8(i1[7],i2[7],cout6,out[7],cout7);
full_adder f9(i1[8],i2[8],cout7,out[8],cout8);
full_adder f10(i1[9],i2[9],cout8,out[9],cout9);
full_adder f11(i1[10],i2[10],cout9,out[10],cout10);
full_adder f12(i1[11],i2[11],cout10,out[11],cout11);
full_adder f13(i1[12],i2[12],cout11,out[12],cout12);
full_adder f14(i1[13],i2[13],cout12,out[13],cout13);
full_adder f15(i1[14],i2[14],cout13,out[14],cout14);
full_adder f16(i1[15],i2[15],cout14,out[15],cout15);
full_adder f17(i1[16],i2[16],cout15,out[16],cout16);
full_adder f18(i1[17],i2[17],cout16,out[17],cout17);
full_adder f19(i1[18],i2[18],cout17,out[18],cout18);
full_adder f20(i1[19],i2[19],cout18,out[19],cout19);
full_adder f21(i1[20],i2[20],cout19,out[20],cout20);
full_adder f22(i1[21],i2[21],cout20,out[21],cout21);
full_adder f23(i1[22],i2[22],cout21,out[22],cout22);
full_adder f24(i1[23],i2[23],cout22,out[23],cout23);
full_adder f25(i1[24],i2[24],cout23,out[24],cout24);
full_adder f26(i1[25],i2[25],cout24,out[25],cout25);
full_adder f27(i1[26],i2[26],cout25,out[26],cout26);
full_adder f28(i1[27],i2[27],cout26,out[27],cout27);
full_adder f29(i1[28],i2[28],cout27,out[28],cout28);
full_adder f30(i1[29],i2[29],cout28,out[29],cout29);
full_adder f31(i1[30],i2[30],cout29,out[30],cout30);
full_adder f32(i1[31],i2[31],cout30,out[31],cout31);





endmodule