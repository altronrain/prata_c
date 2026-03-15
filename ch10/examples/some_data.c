/* some_data.c  -- частично инициализированный массив (non-static) */
#include <stdio.h>
#define SIZE 4

int main (void)
{
	int some_data[SIZE] = {1492, 1066};		/* оставшиеся элементы будут заполнены 0 */
	int i;

	printf ("%2s%14s\n", "i", "no_data[i]");

	for (i = 0; i < SIZE; i++)
		printf ("%2d%14d\n", i, some_data[i]);

	return 0;
}

/*
$ ./some_data 
 i    no_data[i]
 0          1492
 1          1066
 2             0
 3             0
*/