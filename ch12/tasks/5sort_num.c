/* 5sort_num.c  -- сортировка чисел по убыванию в списке

Напишите программму, которая генерирует список из 100 случайных чисел в диапазоне от 1 до 10,
отсортированный по убыванию. (Можете приспособить к типу int алгоритм сортировки из главы 11,
только в этом случае сортируйте сами числа.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 100		/* максимальное количество читаемых строк */

void numsrt (int nums[], int n);

int main (void)
{
	int nums[LIM];		/* массив хранения входных данных */
	int i;

	srand (time (NULL));


	for (i = 0; i < LIM; i++) {
		nums[i] = (rand () % 10) + 1;
	}


	numsrt (nums, LIM);		/* сортировка чисел */
	puts ("\nSorted list:\n");

	for (i = 0; i < LIM; i++)
		printf ("Position %3d, number: %d\n", i + 1, nums[i]);	/* отсортированные числа */

	return 0;
}

/* Сортируем числа по убыванию */
void numsrt (int nums[], int n)
{
	int temp;
	int top, seek;

	/* сортировка выбором. поочередное сравнение элементов с первым и так далее */
	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (nums[top] < nums[seek]) {
				temp = nums[top];
				nums[top] = nums[seek];
				nums[seek] = temp;
			}
}
/*
$ ./5sort_num 

Sorted list:

Position   1, number: 10
Position   2, number: 10
Position   3, number: 10
Position   4, number: 10
Position   5, number: 10
Position   6, number: 10
Position   7, number: 10
Position   8, number: 10
Position   9, number: 10
Position  10, number: 10
Position  11, number: 10
Position  12, number: 9
Position  13, number: 9
Position  14, number: 9
Position  15, number: 9
Position  16, number: 9
Position  17, number: 9
Position  18, number: 9
Position  19, number: 9
Position  20, number: 9
Position  21, number: 9
Position  22, number: 9
Position  23, number: 8
Position  24, number: 8
Position  25, number: 8
Position  26, number: 8
Position  27, number: 8
Position  28, number: 8
Position  29, number: 8
Position  30, number: 8
Position  31, number: 8
Position  32, number: 8
Position  33, number: 8
Position  34, number: 8
Position  35, number: 7
Position  36, number: 7
Position  37, number: 7
Position  38, number: 7
Position  39, number: 7
Position  40, number: 7
Position  41, number: 7
Position  42, number: 7
Position  43, number: 7
Position  44, number: 6
Position  45, number: 6
Position  46, number: 6
Position  47, number: 6
Position  48, number: 6
Position  49, number: 6
Position  50, number: 6
Position  51, number: 6
Position  52, number: 6
Position  53, number: 6
Position  54, number: 5
Position  55, number: 5
Position  56, number: 5
Position  57, number: 5
Position  58, number: 5
Position  59, number: 5
Position  60, number: 5
Position  61, number: 5
Position  62, number: 5
Position  63, number: 5
Position  64, number: 5
Position  65, number: 5
Position  66, number: 4
Position  67, number: 4
Position  68, number: 4
Position  69, number: 4
Position  70, number: 4
Position  71, number: 4
Position  72, number: 4
Position  73, number: 3
Position  74, number: 3
Position  75, number: 3
Position  76, number: 3
Position  77, number: 3
Position  78, number: 3
Position  79, number: 3
Position  80, number: 2
Position  81, number: 2
Position  82, number: 2
Position  83, number: 2
Position  84, number: 2
Position  85, number: 2
Position  86, number: 2
Position  87, number: 2
Position  88, number: 2
Position  89, number: 2
Position  90, number: 2
Position  91, number: 2
Position  92, number: 2
Position  93, number: 1
Position  94, number: 1
Position  95, number: 1
Position  96, number: 1
Position  97, number: 1
Position  98, number: 1
Position  99, number: 1
Position 100, number: 1
*/