#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include <sys/wait.h>




int main(int argc, char **argv) {

    int pid = fork ();

    if (pid == 0) {
        // I am the child
		printf("--------------------- Background process ---------------------\n");
        execv("creator", NULL);
      	exit(0);
    } else {
        exit(0);
    }

    return 0;
}
