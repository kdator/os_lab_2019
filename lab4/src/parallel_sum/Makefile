CC=gcc
CFLAGS=-w -c

all: threads_sum

threads_sum: utils.o ThreadFunctions.o parallel_sum.o
	$(CC) utils.o ThreadFunctions.o parallel_sum.o -o threads -lpthread

utils.o: utils.c
	$(CC) $(CFLAGS) utils.c -o utils.o

ThreadFunctions.o: ThreadFunctions.c
	$(CC) $(CFLAGS) ThreadFunctions.c -o ThreadFunctions.o

parallel_sum.o: parallel_sum.c
	$(CC) $(CFLAGS) parallel_sum.c -o parallel_sum.o

clean:
	rm *.o threads