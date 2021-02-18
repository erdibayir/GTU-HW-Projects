module cu_tb(output testout);
reg [5:0] opcode;
wire regDst,branch,MemRead,MemToReg,MemWrite,ALUSrc,RegWrite;
wire [1:0] AluOp;
	control_unit  cu1(opcode,regDst,branch,MemRead,MemToReg,AluOp,MemWrite,ALUSrc,RegWrite);
	
	initial begin
	opcode = 6'b000000;
	#10
	opcode = 6'b100011;
	#10
	opcode = 6'b101011;
	#10
	opcode = 6'b000100;
	end
initial begin
	$monitor(
	" opcode :%b\nregDst=%b branch=%b MemRead=%b ,MemToReg=%b AluOp=%b MemWrite=%b ALUSrc=%b RegWrite=%b "
	,opcode,regDst,branch,MemRead,MemToReg,AluOp,MemWrite,ALUSrc,RegWrite);
		
	end
endmodule
