#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>

#include "find_min_max.h"
#include "utils.h"

int main(int argc, char **argv) {
  int seed = -1;
  int array_size = -1;
  int pnum = -1;
  bool with_files = false;

  while (true) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"seed", required_argument, 0, 0},
                                      {"array_size", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"by_files", no_argument, 0, 'f'},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "f", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            seed = atoi(optarg);
            // your code here
            // printf("seed %d\n", seed);
            break;
          case 1:
            array_size = atoi(optarg);
            // your code here
            // printf("array_size %d\n", array_size);
            break;
          case 2:
            pnum = atoi(optarg);
            // your code here
            // printf("pnum %d\n", pnum);
            break;
          case 3:
            with_files = true;
            break;

          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      case 'f':
        with_files = true;
        break;

      case '?':
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }


  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (seed == -1 || array_size == -1 || pnum == -1) {
    printf("Usage: %s --seed \"num\" --array_size \"num\" --pnum \"num\" \n",
           argv[0]);
    return 1;
  }

  int *array = malloc(sizeof(int) * array_size);
  GenerateArray(array, array_size, seed);
  int active_child_processes = 0;

  struct timeval start_time;
  gettimeofday(&start_time, NULL);

  /* Making pipes array */
  int pipes_num = pnum * 2;
  int fd[pipes_num][2];
  int step = array_size/pnum;

  /* creating pipes from array */
  if (!with_files) {

       for (int i = 0; i < pipes_num; i++) {
           if (pipe(fd[i])==-1)
           {
               fprintf(stderr, "Pipe Failed" );
               return 1;
           } else {
              // printf("sussesful pipe\n");
          }
       }
  }

  /* clearing file from prew use */
  FILE* cfp;
  cfp = fopen("data.txt", "w+");
  fprintf(cfp, "");
  fclose(cfp);

  for (int i = 0; i < pnum; i++) {
    pid_t child_pid = fork();
    if (child_pid >= 0) {
      // successful fork
      active_child_processes += 1;
      if (child_pid == 0) {
        /* --------------------- child process --------------------- */

        int start_index = i * step;
        int end_index = (i + 1) * step;

        struct MinMax min_max = GetMinMax(array, start_index, end_index);

        if (with_files) {
            /* --------------------- files --------------------- */

            FILE* filePointer;
            int bufferLength = 255;
            char buffer[bufferLength];

            filePointer = fopen("data.txt", "a+");

            fprintf(filePointer, "%d\n%d\n", min_max.min, min_max.max);

            fclose(filePointer);

        } else {
            /* --------------------- pipes --------------------- */

            int current_min_pipe = i * 2;
            int current_max_pipe = i * 2 + 1;


            /*  close reading  */
            close(fd[current_min_pipe][0]);
            close(fd[current_max_pipe][0]);

            int bufferLength = 255;

            char str_min_num[bufferLength];
            char str_max_num[bufferLength];

            sprintf (str_min_num, "%d\n", min_max.min);
            sprintf (str_max_num, "%d\n", min_max.max);

            write(fd[current_min_pipe][1], str_min_num, strlen(str_min_num)+1);
            write(fd[current_max_pipe][1], str_max_num, strlen(str_max_num)+1);

            /*  close writing  */
            close(fd[current_min_pipe][1]);
            close(fd[current_max_pipe][1]);
        }
        return 0;
      }

    } else {
      printf("Fork failed!\n");
      return 1;
    }
  }

  while (active_child_processes > 0) {
    // your code here
    wait(NULL);

    active_child_processes -= 1;
  }

  FILE* filePointer;
  filePointer = fopen("data.txt", "r");

  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;

  for (int i = 0; i < pnum; i++) {
    int min = INT_MAX;
    int max = INT_MIN;

    if (with_files) {
        // read from FILES

        int bufferLength = 255;

        char min_str[bufferLength];
        char max_str[bufferLength];


        fscanf(filePointer, "%s", min_str);
        fscanf(filePointer, "%s", max_str);

        min = atoi(min_str);
        max = atoi(max_str);

        printf("Loaded: min: %d max: %d\n", min, max);


        if (i == pnum - 1) { fclose(filePointer); }


    } else {
        // read from pipes

        int current_min_pipe = i * 2;
        int current_max_pipe = i * 2 + 1;

        /*  close writing  */
        close(fd[current_min_pipe][1]);
        close(fd[current_max_pipe][1]);

        int bufferLength = 255;

        char min_str[bufferLength];
        char max_str[bufferLength];

        read(fd[current_min_pipe][0], min_str, bufferLength);
        read(fd[current_max_pipe][0], max_str, bufferLength);

        min = atoi(min_str);
        max = atoi(max_str);
    }

    if (min < min_max.min) min_max.min = min;
    if (max > min_max.max) min_max.max = max;
  }

  struct timeval finish_time;
  gettimeofday(&finish_time, NULL);

  double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;
  elapsed_time += (finish_time.tv_usec - start_time.tv_usec) / 1000.0;

  /*--------------------- Reference ---------------------*/

  struct timeval sequential_start_time;
  gettimeofday(&sequential_start_time, NULL);

  struct MinMax min_max_reference = GetMinMax(array, 0, array_size);

  struct timeval sequential_finish_time;
  gettimeofday(&sequential_finish_time, NULL);

  double sequential_elapsed_time = (sequential_finish_time.tv_sec - sequential_start_time.tv_sec) * 1000.0;
  sequential_elapsed_time += (sequential_finish_time.tv_usec - sequential_start_time.tv_usec) / 1000.0;

   /* ---------------------------------------------------- */

  free(array);

  printf("Parallel:\n min:%d max:%d\n", min_max.min, min_max.max);
  printf("Sequential:\n min:%d max:%d\n", min_max_reference.min, min_max_reference.max);

  printf("Secquential elapsed time: %fms\n", sequential_elapsed_time);
  printf("Parallel elapsed time: %fms\n", elapsed_time);
  fflush(NULL);
  return 0;
}
