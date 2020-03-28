#include <stdio.h>

#include "swap.h"

int main()
{
	char ch1 = 'a';
	char ch2 = 'b';
	printf("Prew: %c %c\n", ch1, ch2);

	Swap(&ch1, &ch2);

	printf("After: %c %c\n", ch1, ch2);
	return 0;
}
