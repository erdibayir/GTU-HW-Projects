module mux_3_bit_2_1(i1,i2,out,select_b);
input [2:0] i1,i2;
input select_b;
output [2:0] out;

mux_1_bit_2_1 m1(i1[0],i2[0],select_b,out[0]);
mux_1_bit_2_1 m2(i1[1],i2[1],select_b,out[1]);
mux_1_bit_2_1 m3(i1[2],i2[2],select_b,out[2]);

endmodule