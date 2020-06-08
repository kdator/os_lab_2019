CC=gcc
CFLAGS=-I.

all : client servers

client :
	$(CC) -w -o client client.c $(CFLAGS) -lpthread

servers :
	mkdir servers
	$(CC) -w server.c mult_modulo.c -o servers/fst_server $(CFLAGS) -lpthread
	cp servers/fst_server servers/snd_server

libMod :
	gcc -c -fPIC mult_modulo.c -o mod.o
	gcc -shared mod.o -o libMod.so
	
clean :
	rm servers/fst_server servers/snd_server
	rm -r servers
	rm client



# Create the object files
# gcc -c -fPIC mult_modulo.c -o mod.o
# gcc -c server.c -o server.o

# Create the shared library
# gcc -shared mod.o -o libMod.so

# Make servers application using dynamic lib
# gcc -w server.o -L -lMod
