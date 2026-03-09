/* q4.c -- сумма двух целых чисел в виде отдельной функции */
#include <stdio.h>

int sum (int, int);

int main (void)
{
	int n1 = 42, n2 = 146;

	printf ("Сумма чисел %d и %d составляет: %d\n", n1, n2, sum (n1, n2));

	return 0;
}

int sum (int a, int b)
{
	return a + b;
}

/*
$ ./q4 
Сумма чисел 42 и 146 составляет: 188
*/