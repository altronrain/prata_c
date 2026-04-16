/* 7copy2d.c -- копирование двумерных массивов

Напишите программу, которая инициализирует двумерный массив значений типа double
и использует однгу из функций копирования из упражнения 2 для его копирования
во второй двумерный массив. (Поскольку двумерный массив -- это массив массивов,
функция для копирования одномерных массивов может применяться с каждым подмассивов)
*/
#include <stdio.h>

void copy_arr (double [], double [], int);
void print_arr (const double [][5], int n);

int main (void)
{
	double source[5][5] =
	{
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 0.0},
		{1.0, 2.9, 3.8, 4.7, 5.6},
		{6.5, 7.4, 8.3, 9.2, 0.1},
		{1.2, 3.4, 5.6, 7.8, 9.0},

	};
	double target1[5][5];

	for (int i = 0; i < 5; i++)
		copy_arr (target1[i], source[i], 5);

	printf ("Вывод массива target1:\n");
	print_arr (target1, 5);

	return 0;
}

void copy_arr (double tgt[], double src[], int n)
{
	for (int i = 0; i < n; i++) {
		tgt[i] = src[i];
	}
}

void print_arr (const double tgt[][5], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			printf ("tgt[%d][%d] = %.1f\n", i, j, tgt[i][j]);
	}
}
/*
$ ./7copy2d 
Вывод массива target1:
tgt[0][0] = 1.1
tgt[0][1] = 2.2
tgt[0][2] = 3.3
tgt[0][3] = 4.4
tgt[0][4] = 5.5
tgt[1][0] = 6.6
tgt[1][1] = 7.7
tgt[1][2] = 8.8
tgt[1][3] = 9.9
tgt[1][4] = 0.0
tgt[2][0] = 1.0
tgt[2][1] = 2.9
tgt[2][2] = 3.8
tgt[2][3] = 4.7
tgt[2][4] = 5.6
tgt[3][0] = 6.5
tgt[3][1] = 7.4
tgt[3][2] = 8.3
tgt[3][3] = 9.2
tgt[3][4] = 0.1
tgt[4][0] = 1.2
tgt[4][1] = 3.4
tgt[4][2] = 5.6
tgt[4][3] = 7.8
tgt[4][4] = 9.0
*/