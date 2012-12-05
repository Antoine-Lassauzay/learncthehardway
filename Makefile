CFLAGS=-Wall -g

default: all

clean:
	rm *.dSYM -fr
	rm ex1 ex3 ex4

all: ex1 ex3 ex4
