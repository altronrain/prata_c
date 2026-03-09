/* q8.c -- возврат наибольшего целого из трех аргументов */
#include <stdio.h>

int biggest (int, int, int);

int main (void)
{
	int a = 42, b = 5, c = 100;

	printf ("Наибольшее целое среди %d, %d и %d равно: %d\n",
		a, b, c, biggest (a, b, c));

	return 0;
}

int biggest (int a, int b, int c)
{
	int t;

	return (t = a > b ? a : b) > c ? t : c;
}

/*
$ ./q8
Наибольшее целое среди 42, 5 и 100 равно: 100
*/