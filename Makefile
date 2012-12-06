CFLAGS=-Wall -g

default: ex_10_to_19

clean:
	rm *.dSYM -fr
	rm -f ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9
	rm -f ex10 ex11 ex12 ex13 ex14 ex15

ex_1_to_9: ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9
ex_10_to_19: ex10 ex11 ex12 ex13 ex14 ex15
