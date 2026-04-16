/* 4max_index.c -- поиск индекса наибольшего значения в массиве значений double

Напишите функцию, которая возвращает индекс наибольшего значение в массиве значений
типа double. Протестируйте эту функцию с помощью простой программы.
*/
#include <stdio.h>

int index_max (const double [], int);

int main (void)
{
	const double nums[] = {1.1, 2.2, 3.3, 4.4, 20.20, 6.6, 7.7, 8.8};
	int x;

	x = index_max (nums, sizeof nums / sizeof nums[0]);
	printf ("Индекс наибольшего элемента в массиве nums равен %d\n", x);

	return 0;
}

int index_max (const double arr[], int n)
{
	int x;

	for (int max = arr[0], i = 0; i < n; i++)
		if (max < arr[i]) {
			max = arr[i];
			x = i;
		}

	return x;
}
/*
$ ./4max_index 
Индекс наибольшего элемента в массиве nums равен 4
*/