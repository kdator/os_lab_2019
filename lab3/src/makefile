CC=gcc
CFLAGS=-I. -Wall

all: sequential_min_max parallel_min_max second_sequential

second_sequential: second_sequential.o
	$(CC) $(CFLAGS) -o second_sequential second_sequential.o

sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(CFLAGS) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(CFLAGS) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c

utils.o : utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c

find_min_max.o : utils.h find_min_max.h
	$(CC) $(CFLAGS) -o find_min_max.o -c find_min_max.c

second_sequential.o:
	$(CC) $(CFLAGS) -o second_sequential.o -c second_sequential.c

clean :
	rm *.o sequential_min_max parallel_min_max second_sequential
