/* 6reverse.c -- изменение порядка следования содержимого массива значений double

Напишите функцию, которая изменяет порядок следования содержимого массива значений
типа double. Протестируйте эту функцию с помощью простой программы.
*/
#include <stdio.h>

void reverse (double *, double *);

int main (void)
{
	double nums[] = {3.3, 7.7, 2.2, 4.4, 10.1, 6.6, 1.1, 8.8};

	reverse (nums, nums + sizeof nums / sizeof nums[0]);
	for (int i = 0; i < sizeof nums / sizeof nums[0]; i++)
		printf ("nums[%d] = %.1f\n", i, nums[i]);

	return 0;
}

void reverse (double * start, double * end)
{
	end--;	/* point to the last valid element */

	while (start < end) {
		double temp = *start;

		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

/* void reverse2 (double arr[],  int n)
{
	for (int i = 0, j = n -1; i < j; i++, j--) {
		doubl temp = arr[i];

		arr[i] = arr[j];
		arr[j] = temp;
	}

}
*/
/*
$ ./6reverse 
nums[0] = 8.8
nums[1] = 1.1
nums[2] = 6.6
nums[3] = 10.1
nums[4] = 4.4
nums[5] = 2.2
nums[6] = 7.7
nums[7] = 3.3
*/