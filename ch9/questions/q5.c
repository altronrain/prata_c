/* q5.c -- сумма двух чисел с плавающей точкой в виде отдельной функции */
#include <stdio.h>

double sum (double, double);

int main (void)
{
	double n1 = 42.00, n2 = 146.00;

	printf ("Сумма чисел %.2lf и %.2lf составляет: %.2lf\n", n1, n2, sum (n1, n2));

	return 0;
}

double sum (double a, double b)
{
	return a + b;
}

/*
$ ./q5
Сумма чисел 42.00 и 146.00 составляет: 188.00
*/