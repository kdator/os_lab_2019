#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* When a SIGUSR1 signal arrives, set this variable. */
volatile sig_atomic_t usr_interrupt = 0;
volatile sig_atomic_t is_alarm = 0;

void synch_signal (int sig){
  usr_interrupt = 1;
}



/* The child process executes this function. */
void child_function (void) {
  /* Perform initialization. */
  printf ("I'm here!!!  My pid is %d.\n", (int) getpid ());

  /* Let parent know you’re done. */
  kill (getppid (), SIGUSR1);

  /* Continue with execution. */
  puts ("Bye, now....");
  exit (0);
}

void alarmHandler(int signo) {
    puts ("alarmHandler");
    is_alarm = 1;
    // sigaction (SIGALRM, &usr_action, NULL);
}


int main (void) {
  struct sigaction usr_action;
  sigset_t block_mask;
  pid_t child_id;

  /* Establish the signal handler. */
  sigfillset (&block_mask);
  usr_action.sa_handler = synch_signal;
  usr_action.sa_mask = block_mask;
  usr_action.sa_flags = 0;

  //----------------------------PLAYGROUND----------------------------

  printf("PROCESS STARTED\n");




  alarm (7);
  signal(SIGALRM, alarmHandler);
  // alarm (5);

  while (!is_alarm)
      ;





  //----------------------------PLAYGROUND----------------------------

  /* Create the child process. */
  child_id = fork ();
  if (child_id == 0)
    child_function ();          /* Does not return. */

  /* Busy wait for the child to send a signal. */
  while (!usr_interrupt)
    ;

  /* Now continue execution. */
  puts ("That's all, folks!");

  return 0;
}
