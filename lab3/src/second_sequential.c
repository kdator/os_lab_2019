#include <unistd.h>
#include <stdio.h>

int main(int argc, int *argv[]) {
  printf("Программа %s будет выполнена...\n\n",
         argv[0]);
  printf("Выполняется %s\n", argv[0]);
  execv("sequential_min_max", argv);
  return 0;
}