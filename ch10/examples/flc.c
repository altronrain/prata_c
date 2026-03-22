/* flc.c  -- массивы-константы */
#include <stdio.h>
#define COLS 4

int sum2d (const int arr[][COLS], int rows);
int sum (const int arr[], int n);

int main (void)
{
	int total1, total2, total3;
	int *pt1;
	int (*pt2)[COLS];

	pt1 = (int [2]) {10, 20};
	pt2 = (int [2][COLS]) {{1, 2, 3, -9}, {4, 5, 6, -8}};

	total1 = sum (pt1, 2);
	total2 = sum2d (pt2, 2);
	total3 = sum ((int []) {4, 4, 4, 5, 5, 5}, 6);

	printf ("total1 = %d\n", total1);
	printf ("total2 = %d\n", total2);
	printf ("total3 = %d\n", total3);

	return 0;
}

int sum (const int arr[], int n)	/* arr при этом все равно указатель */
{
	int i, tot = 0;

	for (i = 0; i < n; i++)
		tot += arr[i];

	return tot;

}

int sum2d (const int arr[][COLS], int rows)	/* arr при этом все равно указатель */
{
	int r, c, tot = 0;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			tot += arr[r][c];

	return tot;

}

/*
$ ./flc 
total1 = 30
total2 = 4
total3 = 27
*/