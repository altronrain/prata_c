/* q9.c -- вывод программы
Что выведет следующая программа:

#include <stdio.h>

int main (void)
{
	int n, m;

	n = 30;

	do
		printf ("%d|", n);
	while (++n <= 33);

	printf ("\n***\n");

	for (n = 1; n * n < 200; n += 4);
		printf ("%d\n", n);

		printf ("\n***\n");

	for (n = 2, m = 6; n < m; n *= 2, m += 2)
		printf ("%d %d\n", n, m);

	printf ("\n***\n");
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m <= n; m++)
			printf ("=");
		printf ("\n");
	}

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	int n, m;

	n = 30;

	do											/* 30|31|32|33 */
		printf ("%d|", n);
	while (++n <= 33);

	printf ("\n***\n");

	for (n = 1; n * n < 200; n += 4)			/* 1\n5\n9\n13\n */
		printf ("%d\n", n);

		printf ("\n***\n");

	for (n = 2, m = 6; n < m; n *= 2, m += 2)	/* 2 6\n4 8\n8 10\n */
		printf ("%d %d\n", n, m);

	printf ("\n***\n");
	for (n = 5; n > 0; n--)						/* =====\n====\n===\n==\n */
	{
		for (m = 0; m <= n; m++)
			printf ("=");
		printf ("\n");
	}

	return 0;
}

/*
$ ./q9
30|31|32|33|
***
1
5
9
13

***
2 6
4 8
8 10

***
======
=====
====
===
==
*/