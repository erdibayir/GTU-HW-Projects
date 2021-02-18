module alu_control_unit(alu_Op,function_field,alu_Op_out);
input [1:0] alu_Op;
input [5:0] function_field;
output [2:0] alu_Op_out;
wire a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
wire [2:0] b1,b2,b3,b4,b5,b6,b7,b8,b9;


not(a1,alu_Op[1]);
not(a2,alu_Op[0]);


and(a3,alu_Op[1],function_field[1]);
or(alu_Op_out[2],a3,alu_Op[0]); // alu_Op_out[2]
not(a4,alu_Op[1]);
not(a5,function_field[2]);
or(alu_Op_out[1],a4,a5); // alu_Op_out[1]
or(a6,function_field[3],function_field[0]);
and(alu_Op_out[0],a6,alu_Op[1]); // alu_Op_out[0]

endmodule



