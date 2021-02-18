module full_adder_testbench(output testout);
	reg x,y,cin;
	wire s,cout;
	full_adder f1(x,y,cin,s,cout);
	
initial
	begin
	$monitor(
	   "x=%b y=%b cin=%b s=%b cout=%b",
		   x,y,cin,s,cout);	
	 x=0; y=0;cin=0; #10
	 x=1; y=0;cin=0; #10
	
	 x=0; y=1;cin=0; #10
	 x=1; y=1;cin=0; #10
	 x=1; y=1;cin=1; #10
	$finish;
	end

endmodule