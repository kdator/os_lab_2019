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
	$(CC) $(NO_WAR) source/dynamicLib/client.o -Lsource/dynamicLib -lMod -o client $(CFLAGS)


# Make servers application using dynamic lib
servers : mod.o server.o libMod.so
	mkdir source/servers
	$(CC) $(NO_WAR) source/dynamicLib/server.o -Lsource/dynamicLib -lMod -o source/servers/fst_server $(CFLAGS)
	cp source/servers/fst_server source/servers/scd_server

# Create the object file for mod
mod.o :
	mkdir source/dynamicLib
	$(CC) $(NO_WAR) -c -fPIC source/mult_modulo.c -o source/dynamicLib/mod.o $(CFLAGS)

# Create the object file for server
server.o :
	$(CC) $(NO_WAR) -c source/server.c -o source/dynamicLib/server.o $(CFLAGS)

# Create the object file for client
client.o :
	$(CC) $(NO_WAR) -c source/client.c -o source/dynamicLib/client.o $(CFLAGS)

# Create the shared library
libMod.so :
	$(CC) $(NO_WAR) -shared source/dynamicLib/mod.o -o source/dynamicLib/libMod.so $(CFLAGS)

# Removing all files
clean :
	rm -r source/dynamicLib
	rm -r source/servers
	rm client
