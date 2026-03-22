/* vararr2d.c  -- функции, использующие массивы переменной длины (C99) */
#include <stdio.h>
#define ROWS 3
#define COLS 4

int sum2d (int rows, int cols, int arr[rows][cols]);

int main (void)
{
	int i, j;
	int rs = 3, cs = 10;
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	int morejunk[ROWS - 1][COLS + 2] = {
		{20, 30, 40, 50, 60, 70},
		{5, 6, 7, 8, 9, 10}
	};
	int varr[rs][cs];		/* массив переменной длины */

	for (i = 0; i < rs; i++)	/* заполнение массива переменной длины */
		for (j = 0; j < cs; j++)
			varr[i][j] = i * j + j;

	printf ("Традиционный массив 3x5\n");
	printf ("Сумма всех элементов = %d\n", sum2d (ROWS, COLS, junk));
	printf ("Традиционный массив 2x6\n");
	printf ("Сумма всех элементов = %d\n", sum2d (ROWS-1, COLS+2, morejunk));
	printf ("Массив переменной длины 3x10\n");
	printf ("Сумма всех элементов = %d\n", sum2d (rs, cs, varr));

	return 0;
}

int sum2d (int rows, int cols, int arr[rows][cols])	/* arr при этом все равно указатель */
{
	int r, c, tot = 0;

	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++)
			tot += arr[r][c];

	return tot;

}

/*
$ ./vararr2d 
Традиционный массив 3x5
Сумма всех элементов = 80
Традиционный массив 2x6
Сумма всех элементов = 315
Массив переменной длины 3x10
Сумма всех элементов = 270
*/