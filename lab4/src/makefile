CC=gcc
CFLAGS=-I.

showcase : creator
	$(CC) -o showcase zombie_showcase.c $(CFLAGS)

creator :
	$(CC) -o creator zombie_creator.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o ../../lab3/src/utils.h ../../lab3/src/find_min_max.h
	$(CC) -o parallel_min_max find_min_max/utils.o find_min_max/find_min_max.o ../../lab3/src/parallel_min_max.c $(CFLAGS)
	mkdir DataFiles
	touch DataFiles/data.txt
	rm -r find_min_max

utils.o : ../../lab3/src/utils.h
	mkdir find_min_max
	$(CC) -o find_min_max/utils.o -c ../../lab3/src/utils.c $(CFLAGS)

find_min_max.o : ../../lab3/src/utils.h  ../../lab3/src/find_min_max.h
	$(CC) -o find_min_max/find_min_max.o -c ../../lab3/src/find_min_max.c $(CFLAGS)
