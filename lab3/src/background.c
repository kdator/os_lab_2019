#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    int i = 0;
    long sum;
    int pid;
    int status, ret;

    // Default parameters
	char * argv_list[] = {"10", "10", "100", NULL};

    pid = fork ();

    if (pid == 0) {
        // I am the child
		printf("--------------------- Background process ---------------------\n");
        printf("parameters %d\n", argc);
        // Usage by default or entered parameters
		if (argc != 3) {
	      printf("Usage: %s seed arraysize\n", argv[0]);
		  execv("sequential_min_max", argv_list);
	  	} else {
		  printf("Starting.\n");
		  execv("sequential_min_max", argv);
	  	}

      	exit(0);
    }

    // I am the parent

    printf ("Background: Waiting for process to complete...\n");

	if (waitpid(pid, &status, 0) > 0) {

        if (WIFEXITED(status) && !WEXITSTATUS(status))
          printf("program execution successful\n");

        else if (WIFEXITED(status) && WEXITSTATUS(status)) {
            if (WEXITSTATUS(status) == 127) {
                // execv failed
                printf("execv failed\n");
            }
            else
                printf("program terminated normally,"
                   " but returned a non-zero status\n");
        }
        else
           printf("program didn't terminate normally\n");
    }
    else {
       // waitpid() failed
       printf("waitpid() failed\n");
    }
  	exit(0);
}
