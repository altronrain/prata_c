/* designate.c -- использование назначенных инициализаторов */
#include <stdio.h>
#define MONTHS 12

int main (void)
{
	int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
	int index;

	for (index = 0; index < MONTHS; index++)
		printf ("%2d %2d\n", index + 1, days[index]);

	return 0;
}

/*
$ ./designate 
 1 31
 2 29
 3  0
 4  0
 5 31
 6 30
 7 31
 8  0
 9  0
10  0
11  0
12  0
*/