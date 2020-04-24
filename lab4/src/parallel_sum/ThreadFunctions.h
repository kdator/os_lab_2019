/**
 * \file ThreadFunctions.h
 * \brief Описывает интерфейс для работы с потоковыми функциями.
 * \author kolpaov & Fedorov Petr Alekseevich
 */
#ifndef THREAD_FUNCTIONS_H_
#define THREAD_FUNCTIONS_H_

struct SumArgs;

/**
 * \brief Функция считает сумму элементов в одной части массива.
 * \param args указатель на элемент структуры, который содержит указатель
 *             на массива чисел, а так же границы для счёта.
 * \return Сумма элементов в диапазоне.
 */
int Sum(const struct SumArgs *args);

/**
 * \brief Запускает функцию для суммирования элементов в части массива.
 * \param args бестиповой указатель на часть массива, с которого нужно начать подсчёт.
 */
void *ThreadSum(void *args);

#endif /* THREAD_FUNCTIONS_H_ */