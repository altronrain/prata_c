/* 5diff.c -- поиск разницы наибольшего и наименьшего значений в массиве значений double

Напишите функцию, которая возвращает разность между наибольшим и наименьшим элементами в
массиве значений типа double. Протестируйте эту функцию с помощью простой программы.
*/
#include <stdio.h>

double minmax_diff (const double [], int);

int main (void)
{
	const double nums[] = {3.3, 7.7, 2.2, 4.4, 10.1, 6.6, 1.1, 8.8};

	printf ("Разница наибольшего и наименьшего значений массива равна %.3f\n",
		minmax_diff (nums, sizeof nums / sizeof nums[0]));

	return 0;
}

double minmax_diff (const double arr[], int n)
{
	double min = arr[0], max = arr[0];

	for (int i = 0; i < n; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	return max - min;
}
/*
$ ./5diff 
Разница наибольшего и наименьшего значений массива равна 9.000
*/