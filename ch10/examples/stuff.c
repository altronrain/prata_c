/* stuff.c -- использование назначенных инициализаторов без указания размера массива */
#include <stdio.h>

int main (void)
{
	int stuff[] = {1, [6] = 4,9,10};
	int i;

	for (i = 0; i < sizeof stuff / sizeof stuff[0]; i++)
		printf ("%2d %2d\n", i, stuff[i]);

	return 0;
}
/*
$ ./stuff 
 0  1
 1  0
 2  0
 3  0
 4  0
 5  0
 6  4
 7  9
 8 10
*/