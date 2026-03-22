/* array2d.c  -- функции для двумерных массивов */
#include <stdio.h>
#define ROWS 3
#define COLS 4

void sum_rows (int arr[][COLS], int rows);
void sum_cols (int [][COLS], int);
int     sum2d (int (*arr)[COLS], int rows);	/* эквивалентный синтаксис */

int main (void)
{
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};

	sum_rows (junk, ROWS);
	sum_cols (junk, ROWS);

	printf ("Сумма всех элементов = %d\n", sum2d (junk, ROWS));

	return 0;
}

void sum_rows (int arr[][COLS], int rows)	/* вообще зачем передавать int rows? Брать из define */
{
	int r, c, tot;

	for (r = 0; r < rows; r++) {
		tot = 0;
		for (c = 0; c < COLS; c++)
			tot += arr[r][c];	/* тип arr такой же как у junk -- указатель на int[COLS] */
		printf ("строка %d: сумма = %d\n", r, tot);
	}
}

void sum_cols (int arr[][COLS], int rows)	/* вообще зачем передавать int rows? Брать из define */
{
	int r, c, tot;

	for (c = 0; c < COLS; c++) {
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += arr[r][c];
		printf ("столбец %d: сумма = %d\n", c, tot);
	}
}

int sum2d (int arr[][COLS], int rows)	/* вообще зачем передавать int rows? Брать из define */
{
	int r, c, tot = 0;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			tot += arr[r][c];

	return tot;

}

/*
$ ./array2d 
строка 0: сумма = 20
строка 1: сумма = 24
строка 2: сумма = 36
столбец 0: сумма = 17
столбец 1: сумма = 19
столбец 2: сумма = 21
столбец 3: сумма = 23
Сумма всех элементов = 80
*/