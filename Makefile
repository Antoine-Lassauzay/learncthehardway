CFLAGS=-Wall -g

default: all

clean:
	rm *.dSYM -fr
	rm ex1 ex3 ex4 ex5 ex6 ex7 ex8

all: ex1 ex3 ex4 ex5 ex6 ex7 ex8
