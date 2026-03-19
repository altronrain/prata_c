/* arrf.c  -- функции, манипулирующие массивами */
#include <stdio.h>
#define SIZE 5

void show_array (const double arr[], int n);
void mult_array (double arr[], int n, double mult);

int main (void)
{
	double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

	printf ("Исходный массив dip:\n");
	show_array (dip, SIZE);

	mult_array (dip, SIZE, 2.5);

	printf ("Массив dip после вызова функции mult_array():\n");
	show_array (dip, SIZE);

	return 0;
}

void show_array (const double arr[], int n)		/* обещаем не изменять исходный массив */
{
	int i;

	for (i = 0; i < n; i++)
		printf ("%8.3f ", arr[i]);

	putchar ('\n');
}

void mult_array (double arr[], int n, double mult)	/* изменяем исходный массив */
{
	int i;

	for (i = 0; i < n; i++)
		arr[i] *= mult;
}

/*
$ ./arrf 
Исходный массив dip:
  20.000   17.660    8.200   15.300   22.220 
Массив dip после вызова функции mult_array():
  50.000   44.150   20.500   38.250   55.550
*/