# Лабораторная работа №3

## Как жать?

### Назначения кастомных файлов

1. ".gitignore" убирает лишние файлы из видимости Git
2. "backgroundResult.txt"
3. "data.txt" файл для синхронизации потоков (задание 3)
4. "start.sh" файл для демонстрации тестового задания (запускает все, )

### Так как жать?

1. Вводим команду "./start.sh" и СТАРТУЕМ

### Если нада жать сложна ( показать/посмотреть детали )

* Вводим команду "make all" и СТАРТУЕМ (компилит и линкует все задания)
* Вводим команду "make sequential_min_max" и СТАРТУЕМ (компилит и линкует все задание 1)
* Вводим команду "make parallel_min_max" и СТАРТУЕМ (компилит и линкует все задание 2-3)
* Вводим команду "make background" и СТАРТУЕМ (компилит и линкует все задание 5)
* Вводим команду "make clean" и СТАРТУЕМ (удаляет все новые файлы (не работает с 5-ым))
* Вводим команду "make cleanFive" и СТАРТУЕМ (удаляет 5-ое)

### Good links (Maybe better than in lab (better for shure))

#### Getopt:
* http://www.firststeps.ru/linux/r.php?11

#### Pipes:
* https://www.geeksforgeeks.org/creating-multiple-process-using-fork/?ref=rp
* https://www.geeksforgeeks.org/calculation-parent-child-process-using-fork/?ref=rp
* https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/?ref=rp

#### Makefile:
* https://habr.com/en/post/155201/
* https://habr.com/en/post/211751/

#### Exec:
* https://www.geeksforgeeks.org/difference-fork-exec/
* https://www.softprayog.in/programming/creating-processes-with-fork-and-exec-in-linux


## Задание 1

### Необходимые знания

1. Аргументы командной строки
2. Сборка с помощью gcc (clang)

Написать функцию GetMinMax в find\_max\_min.c, которая ищет минимальный и максимальный элементы массива, на заданном промежутке.
Разобраться, что делает программа в sequiential\_min\_max.c, скомпилировать, проверить, что написанный вами GetMinMax работает правильно.

### Ресурсы

1. [Как компилировать простые программы с gcc (заменить сс на gcc).](https://www.classes.cs.uchicago.edu/archive/2014/winter/51081-1/LabFAQ/lab3/compile.html)
2. [Пример с аргументами командной строки.](https://www.cprogramming.com/tutorial/c/lesson14.html)

## Задание 2 - 3

### Необходимые знания

1. Аргументы командной строки
2. Системный вызов `fork`
3. Системный вызов `pipe`
4. Работа с файлами в Си

Завершить программу parallel\_min\_max.c, так, чтобы задача нахождения минимума и максимума в массиве решалась параллельно.
Если выставлен аргумент `by_files` для синхронизации процессов использовать файлы (задание 2), в противном случае использовать pipe (задание 3).

### Ресурсы

1. [Мануал для fork](http://man7.org/linux/man-pages/man2/fork.2.html)
2. [Мануал для pipe](http://man7.org/linux/man-pages/man2/pipe.2.html)
3. [Небольшой туториал для работы с файлами](https://www.cprogramming.com/tutorial/cfileio.html)
4. [fprintf, sprintf](http://en.cppreference.com/w/c/io/fprintf), [scanf, fscanf](http://en.cppreference.com/w/c/io/fscanf) - функции, которые кажутся полезными.

## Задание 4

### Необходимые знания

1. Как работают Makefile'ы

Изучить все targets в makefile, будьте готовы объяснить, за что они отвечают. Используя `makefile`, собрать получившиеся решения. Добавьте target `all`, отвечающий за сборку всех программ.

### Ресурсы

1. [Введение в Makefiles. Ссылка на мини учебник от GNU.](https://www.gnu.org/software/make/manual/html_node/Introduction.html#Introduction)

## Задание 5

### Необходимые знания

1. Системный вызов `exec`

Написать программу, которая запускает в отдельном процессе ваше приложение sequiential\_min\_max. Добавить его сборку в ваш makefile.

1. [Мануал для exec](http://man7.org/linux/man-pages/man3/exec.3.html)
2. [Небольшой пример, как комбинировать fork и exec](https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/)

<!--
## Задание 6

Дополните файл tests.c **(название?)**. Добавьте туда unit тесты, для тестирования GetMinMax.
-->

## Перед тем, как сдавать

Залейте ваш код в ваш репозиторий на GitHub. Убедитесь, что вы не добавляете в репозиторий бинарные файлы (программы, утилиты, библиотеки и т.д.).
