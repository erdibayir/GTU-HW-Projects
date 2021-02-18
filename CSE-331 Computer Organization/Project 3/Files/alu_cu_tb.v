module alu_cu_tb(output testout);
wire [2:0] alu_cu_out;
reg [1:0] alu_op;
reg [5:0]function_field;
	alu_control_unit alu1(alu_op,function_field,alu_cu_out);
	initial begin
		alu_op = 2'b00;
		function_field = 6'b000100;
		#10
		alu_op = 2'b01;
		function_field = 6'b000100;
		#10
		alu_op = 2'b10;
		function_field = 6'b100000;
		#10
		alu_op = 2'b10;
		function_field = 6'b100010;
		#10
		alu_op = 2'b10;
		function_field = 6'b100100;
		#10
		alu_op = 2'b10;
		function_field = 6'b100101;
		#10
		alu_op = 2'b10;
		function_field = 6'b101010;
	end
initial begin
	$monitor(
	"Alu Op : %b Function Field:%b\nAlu Control Unit Out=%b",alu_op,function_field,alu_cu_out);
		
	end

endmodule