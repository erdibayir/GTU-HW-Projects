module control_unit(opcode,regDst,branch,MemRead,MemToReg,AluOp,MemWrite,ALUSrc,RegWrite);
input [5:0] opcode;
output regDst,branch,MemRead,MemToReg,MemWrite,ALUSrc,RegWrite;
output [1:0] AluOp;
wire a1,a2,a3,a4,a5,a6,r_type,lw,sw,beq;
not(a1,opcode[5]);
not(a2,opcode[4]);
not(a3,opcode[3]);
not(a4,opcode[2]);
not(a5,opcode[1]);
not(a6,opcode[0]);

and(r_type,a1,a2,a3,a4,a5,a6);
and(lw,opcode[5],a2,a3,a4,opcode[1],opcode[0]);
and(sw,opcode[5],a2,opcode[3],a4,opcode[1],opcode[0]);
and(beq,a1,a2,a3,opcode[2],a5,a6);

or(RegWrite,r_type,lw);
or(ALUSrc,lw,sw);
and(regDst,r_type,r_type);
and(MemToReg,lw,lw);
and(MemRead,lw,lw);
and(MemWrite,sw,sw);
and(branch,beq,beq);
and(AluOp[1],r_type);
and(AluOp[0],beq);


endmodule