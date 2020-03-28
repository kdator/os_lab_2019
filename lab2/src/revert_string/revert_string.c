#include "revert_string.h"
#define LEFT_ELEMENT str[i]
#define RIGHT_ELEMENT str[length - i -1]

void RevertString(char *str)
{

    printf("LINKED_LIBRARY\n");

    int index = 0;
    int length = 0;
    char container;

	while (str[index] != '\0') {
        index++;
        length++;
    }


    for (int i = 0; i < length / 2; i++) {
        container = LEFT_ELEMENT;
        LEFT_ELEMENT = RIGHT_ELEMENT;
        RIGHT_ELEMENT = container;

    }



}
