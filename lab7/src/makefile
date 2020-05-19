CC=gcc
CFLAGS=-I.
NO_WAR = -w

all : tcpClient tcpServer udpClient udpServer task_tcpClient task_tcpServer task_udpClient task_udpServer
	tcpClient
	tcpServer
	udpClient
	udpServer
	task_tcpClient
	task_tcpServer
	task_udpClient
	task_udpServer

# Removing all files
clean :
	rm -r manualApps/
	rm -r automaticApps/

# Compilation of complete TCP client
tcpClient : manualApps
	$(CC) $(NO_WAR) donesrc/tcpclient.c -o manualApps/tcpClient $(CFLAGS)

# Compilation of complete TCP server
tcpServer : manualApps
	$(CC) $(NO_WAR) donesrc/tcpserver.c -o manualApps/tcpServer $(CFLAGS)

# Compilation of complete UDP client
udpClient : manualApps
	$(CC) $(NO_WAR) donesrc/udpclient.c -o manualApps/udpClient $(CFLAGS)

# Compilation of complete UDP server
udpServer : manualApps
	$(CC) $(NO_WAR) donesrc/udpserver.c -o manualApps/udpServer $(CFLAGS)

# Compilation of raw TCP client
task_tcpClient : automaticApps
	$(CC) $(NO_WAR) rawsrc/tcpclient.c -o automaticApps/tcpClient $(CFLAGS)

# Compilation of raw TCP server
task_tcpServer : automaticApps
	$(CC) $(NO_WAR) rawsrc/tcpserver.c -o automaticApps/tcpServer $(CFLAGS)

# Compilation of raw UDP client
task_udpClient : automaticApps
	$(CC) $(NO_WAR) rawsrc/udpclient.c -o automaticApps/udpClient $(CFLAGS)

# Compilation of raw UDP server
task_udpServer : automaticApps
	$(CC) $(NO_WAR) rawsrc/udpserver.c -o automaticApps/udpServer $(CFLAGS)

manualApps :
	mkdir manualApps

automaticApps :
	mkdir automaticApps
