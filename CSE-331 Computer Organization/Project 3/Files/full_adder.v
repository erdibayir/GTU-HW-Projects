module full_adder(x,y,cin,s,cout);

input x,y,cin;
output s,cout;
wire s1,c1,c2,c3;
xor(s1,x,y);
xor(s,cin,s1);
and g1(c1,x,y);
and g2(c2,y,cin);
and g3(c3,x,cin);
or(cout,c1,c2,c3);

endmodule
