/* no_data.c  -- неинициализированный массив (non-static) */
#include <stdio.h>
#define SIZE 4

int main (void)
{
	int no_data[SIZE];
	int i;

	printf ("%2s%14s\n", "i", "no_data[i]");

	for (i = 0; i < SIZE; i++)
		printf ("%2d%14d\n", i, no_data[i]);

	return 0;
}

/*
$ ./no_data 
 i    no_data[i]
 0             0
 1             0
 2     859694528
 3         32610
*/