module xor_(res, a, b);
input a, b;
output res;
wire na, nb;
wire and1, and2;

	not (na, a);
	not (nb, b);
	
	and (and1, a, nb);
	and (and2, na, b);
	
	or (res, and1, and2);

endmodule