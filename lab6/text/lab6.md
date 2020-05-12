# Лабораторная работа №6

### Good links (Maybe better than in lab (better for shure (everything is better than nothing)))

#### Network theory ( TCP/IP, OSI:
* Differences between TCP and UDP https://www.geeksforgeeks.org/differences-between-tcp-and-udp/
* User Datagram Protocol (UDP) https://www.geeksforgeeks.org/user-datagram-protocol-udp/
* TCP/IP https://habr.com/en/post/326574/
* OSI https://ru.wikipedia.org/wiki/Сетевая_модель_OSI
* More TCP info https://www.geeksforgeeks.org/tcp-congestion-control/
* TCP system calls deeper https://www.ibm.com/developerworks/ru/library/au-tcpsystemcalls/index.html
* System calls basics https://ru.bmstu.wiki/Системный_вызов
* Process context http://citforum.ck.ua/hardware/app_kis/glava_61.shtml

#### Terminal theory:
* Background start https://1cloud.ru/help/linux/linux_zapusk_komand_fonovom_rezhime
* Installation gcc https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/
* If there are problems with pthread https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux

#### System functions and structures:
* Send(2) https://linux.die.net/man/2/send
* Send(2) https://pubs.opengroup.org/onlinepubs/009695399/functions/send.html
* Struct sockaddr_in https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
* Htons https://linux.die.net/man/3/htons
* Connect http://man7.org/linux/man-pages/man2/connect.2.html
* Setsockopt https://linux.die.net/man/2/setsockopt

#### Examples TCP progs:
* Bash commands https://www.tenouk.com/Module40c.html
* Simplest example https://www.binarytides.com/server-client-example-c-sockets-linux/
* Deepest explanation http://www.linuxhowtos.org/C_C++/socket.htm

#### TCP server Networking and Socket Programming tutorial in C and с++:
* Video tutorial https://www.youtube.com/watch?v=cNdlrbZSkyQ
* Text tutorial https://www.codeproject.com/articles/586000/networking-and-socket-programming-tutorial-in-c


## Задание 1 Done

### Необходимые знания

1. TCP и TCP/IP
2. TCP vs UDP
1. Системный вызов `socket`
2. Системный вызов `bind`
2. Системный вызов `listen`
3. Системный вызов `accept`
4. Системный вызов `recv`
5. Системный вызов `send`
6. Системный вызов `close`
7. Системный вызов `connect`

В предыдущей лабораторной работе вы распаралелливали вычисление факториала по модулю с помощью потоков. В этой работе вы пойдете еще дальше: вы распараллелите эту работу еще и между серверами.

Необходимо закончить `client.c` и `server.c`:

Клиент в качетсве аргументов командной сроки получает `k`, `mod`, `servers`, где `k` это факториал, который необходимо вычислить (`k! % mod`), `servers` это путь до файла, который содержит сервера (`ip:port`), между которыми клиент будет распараллеливать соединения.

Сервер получает от клиента "кусок" своих вычислений и `mod`, в ответ отсылает клиенту результат этих вычислений.

### Ресурсы

1. [Manual pages](http://man7.org/linux/man-pages/)
2. [TCP [Wikipedia]](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)

### Заметка

Обратите внимание, что клиент сейчас дожидается завершения работы с каждым сервером в цикле, т.е. последовательно. Это значит, что вам нужно подумать, как распараллелить работу с каждым сервером, чтобы сервера могли работать параллельно. Есть несколько вариантов, как это можно сделать, опираясь на уже пройденный вами материал, никто вас не ограничивает в выборе способа, но выбранный вариант вам необходимо объяснить.

## Задание 2 Done

Создать makefile для программ клиента и сервера

## Задание 3

Найти дублирующийся код в двух приложениях и вынести его в библиотеку. Добавить изменения в makefile.

## Задание 4 (опционально)

Получить доступ из внешнего мира. Преподаватель может попросить вас объединиться с другим студентом, чтобы проденмонстрировать, как будет работать ваш сервер с чужим клиентом. Для этого в Codenvy зайдите в Servers (Dashboard->Workspace->Servers), добавьте порт, на котором будет висеть ваш сервер, презагрузите workspace на этой же вкладке браузера. Рядом с созданным "сервером" вы должны увидеть "белый" адрес, по которому вы можете обратиться к вашему серверу.

## Перед тем, как сдавать

Залейте ваш код в ваш репозиторий на GitHub. Убедитесь, что вы не добавляете в репозиторий бинарные файлы (программы, утилиты, библиотеки и т.д.).
