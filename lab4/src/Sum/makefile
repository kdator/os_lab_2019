CC=gcc
CFLAGS=-I.

sum : utils.o utils.h
	$(CC) -o sum resources/utils.o parallel_sum.c $(CFLAGS)

utils.o : utils.h
	mkdir resources
	$(CC) -o resources/utils.o -c utils.c $(CFLAGS)
