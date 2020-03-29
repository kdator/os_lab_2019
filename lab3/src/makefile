CC=gcc
CFLAGS=-I.


all : sequential_min_max parallel_min_max background
	parallel_min_max
	sequential_min_max
	background

sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o sequential_min_max find_min_max/find_min_max.o find_min_max/utils.o sequential_min_max.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max find_min_max/utils.o find_min_max/find_min_max.o parallel_min_max.c $(CFLAGS)
	mkdir DataFiles
	touch DataFiles/data.txt

utils.o : utils.h
	mkdir find_min_max
	$(CC) -o find_min_max/utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max/find_min_max.o -c find_min_max.c $(CFLAGS)

background : background.c
	$(CC) -o background background.c $(CFLAGS)
	mkdir DataFiles
	touch DataFiles/backgroundResult.txt

cleanFive :
	rm background
	rm -r DataFiles


clean :
	rm -r find_min_max DataFiles
	rm sequential_min_max parallel_min_max background
