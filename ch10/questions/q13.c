/* q13.c -- написать вызовы функций на основе прототипов

Имееются следующие прототипы функций:

void show  (const double ar[], int n);
void show2 (const double ar2[][3], int n);

* Напишите вызов функции, который передает show() составной литерал, содержащий значения 8, 3, 9 и 2
* Напишите вызов функции, который передает show2() составной литерал, содержащий значения 8, 3 и 9
в первой строке и значения 5, 4 и 1 по второй строке

*/
#include <stdio.h>

void show  (const double ar[], int n);
void show2 (const double ar2[][3], int n);

int main (void)
{
	show  ((double []) {8, 3, 9, 2}, 4);
	show2 ((double [2][3]) {{8, 3, 9}, {5, 4, 1}}, 2);

	return 0;
}

void show (const double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf ("ar[%d] = %f\n", i, ar[i]);

	return;
}

void show2 (const double ar2[][3], int n)
{
	int r, c;

	for (r = 0; r < n; r++) {
		for (c = 0; c < 3; c++)
			printf ("ar2[%d][%d] = %f\n", r, c, ar2[r][c]);
	}

	return;
}

/*
$ ./q13 
ar[0] = 8.000000
ar[1] = 3.000000
ar[2] = 9.000000
ar[3] = 2.000000
ar2[0][0] = 8.000000
ar2[0][1] = 3.000000
ar2[0][2] = 9.000000
ar2[1][0] = 5.000000
ar2[1][1] = 4.000000
ar2[1][2] = 1.000000
*/