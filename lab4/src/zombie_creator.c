#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include <sys/wait.h>




int main(int argc, char **argv) {

    pid_t child_pid = fork();
    if (child_pid >= 0) {
        // successful fork
        if (child_pid == 0) {
            /* --------------------- zombie process --------------------- */
            printf("ZOMBEE CREATED");
            exit (0);
        } else {
            sleep(30);
            printf("Parrent died\n");
        }

    } else {
        printf("Fork failed!\n");
        return 1;
    }


    return 0;
}
