/* 3max_int.c -- поиск наибольшего значения в массиве значений int

Напишите функцию, которая возвращает наибольшее значение в массиве значений
типа int. Протестируйте эту функцию с помощью простой программы.
*/
#include <stdio.h>

int maxgest (const int [], int);

int main (void)
{
	const int nums[] = {1, 5, -8, 0, 100, 50, 1000, 999, 6, 2};
	int x;

	x = maxgest (nums, sizeof nums / sizeof nums[0]);
	printf ("Наибольшее целое в массиве nums равно %d\n", x);

	return 0;
}

int maxgest (const int arr[], int n)
{
	int res = arr[0];

	for (int i = 0; i < n; i++)
		if (res < arr[i]) res = arr[i];

	return res;
}
/*
$ ./3max_int 
Наибольшее целое в массиве nums равно 1000
*/