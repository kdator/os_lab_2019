#include <pthread.h>
#include <stdio.h>

pthread_mutex_t first_deadlock_mutex;
pthread_mutex_t second_deadlock_mutex;
static int first_variable = 1;
static int second_variable = 1;

void *deadlock_first(void *args) {
  pthread_mutex_lock(&first_deadlock_mutex);
  first_variable++;
  second_variable++;
  pthread_mutex_lock(&second_deadlock_mutex);
}

void *deadlock_second(void *args) {
  pthread_mutex_lock(&second_deadlock_mutex);
  first_variable++;
  second_variable++;
  pthread_mutex_lock(&first_deadlock_mutex);
}

int main() {

  pthread_t threads[2];
  pthread_mutex_init(&first_deadlock_mutex, NULL);
  pthread_mutex_init(&second_deadlock_mutex, NULL);
  pthread_create(&threads[0], NULL, deadlock_first, NULL);
  pthread_create(&threads[1], NULL, deadlock_second, NULL);
  for (int i = 0; i < 2; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("First - %i\nSecond - %i\n", first_variable, second_variable);
  return 0;
}