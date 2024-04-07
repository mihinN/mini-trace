.DEFAULT_GOAL := all

CC=gcc

clean:
	rm -rf *.o
	rm -rf *.out

compile:
	$(CC) -c minigun.c -o mini-trace.o -m32

link:
	$(CC) -o mini-trace mini-trace.o 

all: clean compile link
