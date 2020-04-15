#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>

#include <stdbool.h>

#include "utils.h"


struct SumArgs {
    int *array;
    int begin;
    int end;
};

void print_array(int* array, int size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_SumArgs_array(const struct SumArgs *args) {
    for (size_t i = args->begin; i < args->end; i++) {
        printf("%d ", args->array[i]);
    }
    printf("\n");
}

int Sum(const struct SumArgs *args) {
    int sum = 0;
    for (size_t i = args->begin; i < args->end; i++) {
        sum += args->array[i];
    }
    return sum;
}


// interaction with Sum layer
/* converting to our type and sending to our Function */
void *ThreadSum(void *args) {
    struct SumArgs *sum_args = (struct SumArgs *)args;
    return (void *)(size_t)Sum(sum_args);
}

int main(int argc, char **argv) {

    uint32_t threads_num = -1;
    uint32_t array_size = -1;
    uint32_t seed = -1;
    int border = -1;

    while (true) {
        int current_optind = optind ? optind : 1;

        static struct option options[] = {{"seed", required_argument, 0, 0},
                                        {"array_size", required_argument, 0, 0},
                                        {"threads_num", required_argument, 0, 0},
                                        {"border", required_argument, 0, 0},
                                        {0, 0, 0, 0}};

        int option_index = 0;

        /* Function for reading flags in input */
        int c = getopt_long(argc, argv, "f", options, &option_index);

        if (c == -1) break;
        switch (c) {
            case 0:
                switch (option_index) {
                    case 0:
                        seed = atoi(optarg);
                        // your code here
                        if (seed <= 0) {
                            printf("seed must be positiv number (better if bigger than 5)%d\n", seed);
                            return 1;
                        }
                        break;
                    case 1:
                        array_size = atoi(optarg);
                        // your code here
                        if (array_size <= 0) {
                            printf("array_size must be positiv number (better if bigger than 5)%d\n", array_size);
                            return 1;
                        }
                        break;
                    case 2:
                        threads_num = atoi(optarg);
                        // your code here
                        if (threads_num <= 0) {
                            printf("threads_num must be positiv number (better if bigger than 5)%d\n", threads_num);
                            return 1;
                        }
                        break;
                    case 3:
                        border = atoi(optarg);
                        // your code here
                        if (border <= 0) {
                            printf("border must be positiv number (better if bigger than 5)%d\n", border);
                            return 1;
                        }
                        break;
                    defalut:
                    printf("Index %d is out of options\n", option_index);
                }
                break;
            default:
                printf("getopt returned character code 0%o?\n", c);
        }
    }

    if (optind < argc) {
        printf("Has at least one no option argument\n");
        return 1;
    }

    if (seed == -1 || array_size == -1 || threads_num == -1) {
        printf("Usage: %s --seed \"num\" --array_size \"num\" --threads_num \"num\" \n",
        argv[0]);
        return 1;
    }

    printf("\n----------------------------\n");
    // printf("seed %d, array_size: %d threads_num: %d, border: %d \n",seed, array_size, threads_num, border);

    int *array = malloc(sizeof(int) * array_size);
    if (border < 0) { border = 100; }
    GenerateArray(array, array_size, seed, border);

    pthread_t threads[threads_num];
    int  i_returns[threads_num];

    // start of time counting
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // step for dividing
    int step = array_size/threads_num;
    struct SumArgs array_pieces[threads_num];

    /* Create independent threads each of which will execute function */
    for (size_t i = 0; i < threads_num; i++) {

        // dividing array by parts to calculate
        int start_index = i * step;
        int end_index = (i + 1) * step;

        /* flexibility for not round arrays */
        if (i == threads_num -1) { end_index = array_size;}

        array_pieces[i].array = array;
        array_pieces[i].begin = start_index;
        array_pieces[i].end = end_index;

        i_returns[i] = pthread_create( &threads[i], NULL, ThreadSum, (void*) &(array_pieces[i]));
    }


    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */

    int total_sum = 0;
    for (uint32_t i = 0; i < threads_num; i++) {
        int sum = 0;
        pthread_join(threads[i], (void **)&sum);
        total_sum += sum;
        if (i_returns[i]) {
            printf("Thread %d had an error: %d\n", i, i_returns[i]);
        }
    }

    // sleep(1); /* uncomment for time showing */
    // end of time counting
    struct timeval finish_time;
    gettimeofday(&finish_time, NULL);

    struct SumArgs st_array;
    st_array.array = array;
    st_array.begin = 0;
    st_array.end = array_size;
    int reference = Sum(&st_array);

    double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;

    free(array);
    printf("Total: %d\nReference: %d\n", total_sum, reference);
    printf("Parallel elapsed time: %fms\n", elapsed_time);
    printf("----------------------------\n");
    return 0;
}
