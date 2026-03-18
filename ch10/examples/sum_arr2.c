/* sum_arr2.c  -- сумма элементов массива */
#include <stdio.h>
#define SIZE 10

int sum (int *start, int *end);

int main (void)
{
	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	long answer;

	answer = sum (marbles, marbles + SIZE);		/* marbles + SIZE -- ячейка за массивом */
	printf ("Общая сумма элементов массива marbles равна %ld.\n", answer);

	return 0;
}

int sum (int *start, int *end)
{
	int total = 0;

	while (start < end) {		/* потому что end указывает на элемент за массивом */
		total += *start;	/* добавить значение к total */
		start++;		/* переместить указатель на следующий элемент */
	}

	return total;
}

/*
$ ./sum_arr2
Общая сумма элементов массива marbles равна 190.
*/