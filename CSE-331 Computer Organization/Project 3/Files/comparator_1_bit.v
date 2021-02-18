module comparator_1_bit (i1, i2, less, equal,greater);
input i1, i2;
output less, equal,greater;
wire a1, a2;
not X1(a1, i1);
not X2 (a2, i2);
and X3 (less,a1, i2);
and X4 (greater,a2, i1);
xnor X5 (equal, i1, i2);
endmodule