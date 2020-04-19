#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include <pthread.h>

#include "utils.h"

int Sum(const struct SumArgs *args) {
  int sum = 0;
  for (size_t i = args->begin; i < args->end; i++) {
    sum += args->array[i];
  }
  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(size_t)Sum(sum_args);
}

int main(int argc, char **argv) {

  uint32_t threads_num = -1;
  uint32_t array_size = -1;
  uint32_t seed = -1;

  while (1) {
    static struct option options[] = {{"threads_num", required_argument, 0, 0},
                                      {"array_size", required_argument, 0, 0},
                                      {"seed", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "?", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            threads_num = atoi(optarg);
            break;
          case 1:
            array_size = atoi(optarg);
            break;
          case 2:
            seed = atoi(optarg);
            break;
        }
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

  if (threads_num == -1 || array_size == -1 || seed == -1) {
        printf("Usage: %s --threads_num \"num\" --array_size \"num\" --seed \"num\" \n",
           argv[0]);
    return 1;
  }


  pthread_t threads[threads_num];
  struct SumArgs args[threads_num];

  int *array = (int*)malloc(sizeof(int) * array_size);
  GenerateArray(array, array_size, seed);
  int sum = 0;
  for (int i = 0; i < array_size; i++) {
    sum += array[i];
  }
  printf("%i ", sum);
  
  int active_step = threads_num < array_size ? (array_size / threads_num) : 1;
  for (uint32_t i = 0; i < threads_num; i++) {
    if (i == threads_num - 1)
      args[i].end = array_size;

    args[i].array = array;
    args[i].begin = active_step * i;
    args[i].end = (i + 1) * active_step;
  }

  for (uint32_t i = 0; i < threads_num; i++) {
    if (pthread_create(&threads[i], NULL, ThreadSum, (void *)&args[i])) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }

  int total_sum = 0;
  for (uint32_t i = 0; i < threads_num; i++) {
    int sum = 0;
    pthread_join(threads[i], (void **)&sum);
    total_sum += sum;
  }

  free(array);
  printf("Total: %d\n", total_sum);
  return 0;
}