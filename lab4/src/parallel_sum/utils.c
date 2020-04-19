#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Генерация происходит стандартной функцией rand(). */
void GenerateArray(int *array, unsigned int array_size, unsigned int seed) {
  srand(seed);
  for (int i = 0; i < array_size; i++) {
    array[i] = rand() % 100;
  }
}