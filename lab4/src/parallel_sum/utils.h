/**
 * \file utils.h
 * \brief Файл, содержащий дополниельные структуры данных.
 * \author kolpakov && Fedorov P.A..
 */
#ifndef UTILS_H
#define UTILS_H

/**
 * \brief Структура, которая описывает диапозоны для суммирования элементов
 *        в массиве.
 */
struct SumArgs {
  int *array; /**< указатель на массив, в котором будет идти суммирование. */
  int begin; /**< индекс для начала суммирования элементов. */
  int end; /**< индекс для окончания суммирования элементов. */
};

/**
 * \brief Генерирует массив целых чисел.
 * \param array указатель на целочисленный массив, куда будет идти генерация чисел.
 * \param array_size количество элементов для генерации.
 * \param seed "семя" для генерации элементов.
*/
void GenerateArray(int *array, unsigned int array_size, unsigned int seed);

#endif /* UTILS_H_ */