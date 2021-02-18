module mux_1_bit_2_1(i1,i2,select_b,out);

input i1,i2,select_b;
output out;

wire r_select_b;
wire a1,a2;
not(r_select_b,select_b);
and(a1,r_select_b,i1);
and(a2,i2,select_b);
or(out,a1,a2);

endmodule