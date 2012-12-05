CFLAGS=-Wall -g

default: all

clean:
	rm -fr ex1 ex1.dSYM
	rm -fr ex3 ex3.dSYM
	rm -fr ex4 ex4.dSYM
	
all: ex1 ex3 ex4