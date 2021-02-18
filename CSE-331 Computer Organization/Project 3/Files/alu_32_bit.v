module alu_32_bit(i1,i2,alu_op,zero_bit,out);
input [31:0] i1,i2;
input [2:0] alu_op;
output [31:0] zero_bit;
output [31:0] out;
wire a1,a7;
wire [31:0] a2,a3,a4,a5,a6,a9,a10,a11,a12,a13;
wire dc; // dont care
wire b1,b2,b3,b4,b5,b6,b7,b8;

// and alu op code a4 = 0
not(b1,alu_op[2]);
not(b2,alu_op[1]);
not(b3,alu_op[0]);

and(b4,b1,b2,b3); // And 000
and(b5,b1,alu_op[1],b3); // Add 010
and(b6,b1,b2,alu_op[0]); // Or 001
and(b7,alu_op[2],alu_op[1],alu_op[0]);// xor 111
and(b8,alu_op[2],alu_op[1],b3); // substract 110 

and_32_bit and1(i1,i2,a2);
or_32_bit or1(i1,i2,a3);
adder_32_bit add1(i1,i2,a4);
xor_32_bit xor1(i1,i2,a5);
sub_32_bit sub1(i1,i2,a6);
mux_32_bit_2_1 mux1(32'b0,a2,a9,b4); //(i1 and i2)
mux_32_bit_2_1 mux2(a9,a3,a10,b6);//(i1 or i2)
mux_32_bit_2_1 mux3(a10,a4,a11,b5); // (i1 + i2)
mux_32_bit_2_1 mux4(a11,a5,a12,b7); // (i1 xor i2)
mux_32_bit_2_1 mux5(a12,a6,a13,b8); // (i1 - i2)

mux_32_bit_2_1 mux6(a13,32'b0,out,1'b0); // out = a13


and_32_bit and2(a6,a6,zero_bit);
endmodule