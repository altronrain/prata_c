/* 9val.c -- копирование и вывод массивов переменной длины

Напишите программу, которая инициализирует двумерный массив 3x5 значений типа
double и использует функцию, основанную на массивах переменной длины, для
копирования этого массива во второй двумерный массив. Кроме того, напишите
функцию, основанную на массивах переменной длины, для отображения содержимого
этих двух массивов. В общем случае обе функции должны дыть способны обрабатывать
произвольные массивы NxM. (Если вы не имеете доступа к компилятору, поддерживающему
массивы переменной длины, примените традиционный подход C с функциями, которые
могут обрабатывать массивы Nx5).
*/
#include <stdio.h>

void copy_val_arr (int, int, double [*][*], double [*][*]);
void print_val_arr(int n, int m, const double arr[n][m], char *);

int main (void)
{
	double source[3][5] =
	{
		{1.1, 2.2, 3.3, 4.4, 5.5},
		{6.6, 7.7, 8.8, 9.9, 0.0},
		{1.2, 3.4, 5.6, 7.8, 9.0}

	};
	double target[3][5];


	copy_val_arr (3, 5, target, source);
	print_val_arr (3, 5, target, "target");
	print_val_arr (3, 5, source, "source");

	return 0;
}

void copy_val_arr (int n, int m, double tgt[n][m], double src[n][m])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tgt[i][j] = src[i][j];
}

void print_val_arr(int n, int m, const double arr[n][m], char *name)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%s[%d][%d] = %.1f\n", name, i, j, arr[i][j]);

	printf("\n");
}
/*
$ ./9val 
target[0][0] = 1.1
target[0][1] = 2.2
target[0][2] = 3.3
target[0][3] = 4.4
target[0][4] = 5.5
target[1][0] = 6.6
target[1][1] = 7.7
target[1][2] = 8.8
target[1][3] = 9.9
target[1][4] = 0.0
target[2][0] = 1.2
target[2][1] = 3.4
target[2][2] = 5.6
target[2][3] = 7.8
target[2][4] = 9.0

source[0][0] = 1.1
source[0][1] = 2.2
source[0][2] = 3.3
source[0][3] = 4.4
source[0][4] = 5.5
source[1][0] = 6.6
source[1][1] = 7.7
source[1][2] = 8.8
source[1][3] = 9.9
source[1][4] = 0.0
source[2][0] = 1.2
source[2][1] = 3.4
source[2][2] = 5.6
source[2][3] = 7.8
source[2][4] = 9.0
*/