CC=gcc
CFLAGS=-I.
NO_WAR = -w
# $(NO_WAR)
# $(CC) -w -o client source/client.c $(CFLAGS)

all : client servers
	client
	servers

# Make servers application using dynamic lib
client : mod.o libMod.so client.o
	gcc -w source/dynamicLib/client.o -Lsource/dynamicLib -lMod -o client


# Make servers application using dynamic lib
servers : mod.o server.o libMod.so
	mkdir source/servers
	gcc -w source/dynamicLib/server.o -Lsource/dynamicLib -lMod -o source/servers/fst_server
	cp source/servers/fst_server source/servers/scd_server

# Create the object file for mod
mod.o :
	mkdir source/dynamicLib
	gcc -c -fPIC source/mult_modulo.c -o source/dynamicLib/mod.o

# Create the object file for server
server.o :
	gcc -c source/server.c -o source/dynamicLib/server.o

# Create the object file for client
client.o :
	gcc -c source/client.c -o source/dynamicLib/client.o

# Create the shared library
libMod.so :
	gcc -shared source/dynamicLib/mod.o -o source/dynamicLib/libMod.so

# Removing all files
clean :
	rm -r source/dynamicLib
	rm -r source/servers
	rm client
