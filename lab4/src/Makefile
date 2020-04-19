CC=gcc
CFLAGS=-w -c

all: memory zombie

memory: process_memory.o
	$(CC) process_memory.o -o memory

zombie: zombie.o
	$(CC) zombie.o -o zombie

process_memory.o: process_memory.c
	$(CC) $(CFLAGS) process_memory.c -o process_memory.o

zombie.o: zombie.c
	$(CC) $(CFLAGS) zombie.c -o zombie.o

clean :
	rm *.o memory zombie