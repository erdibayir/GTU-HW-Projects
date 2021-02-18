module mux_5_bit_2_1(i1,i2,out,select_b);
input [4:0] i1,i2;
input select_b;
output [4:0] out;

mux_1_bit_2_1 m1(i1[0],i2[0],select_b,out[0]);
mux_1_bit_2_1 m2(i1[1],i2[1],select_b,out[1]);
mux_1_bit_2_1 m3(i1[2],i2[2],select_b,out[2]);
mux_1_bit_2_1 m4(i1[3],i2[3],select_b,out[3]);
mux_1_bit_2_1 m5(i1[4],i2[4],select_b,out[4]);

endmodule