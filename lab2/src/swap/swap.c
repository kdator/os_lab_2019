#include "swap.h"

void Swap(char *left, char *right)
{
	char container = *left;
    *left = *right;
    *right = container;
}

// gcc swap.c main.c -o Task1 && ./Task1 
