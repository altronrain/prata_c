/* 14process_val_arr.c -- вычисления с массивами переменной длины

Выполните упражнение 13, но используйте в качестве параметров функции массивы
переменной длины
*/
#include <stdio.h>
#define ROWS 3
#define COLS 5

void save_arr (int, int, double [*][*]);
void mean_row (int, const double []);
double mean_arr (int, int, const double [*][*]);
double max_arr  (int, int, const double [*][*]);
void print_arr(int, int, const double [*][*]);

int main (void)
{
	double arr[ROWS][COLS];
	double mean, max;

	save_arr (ROWS, COLS, arr);
	print_arr(ROWS, COLS, arr);
	for (int i = 0; i < ROWS; i++)
		mean_row (COLS, arr[i]);
	mean = mean_arr (ROWS, COLS, arr);
	max = max_arr (ROWS, COLS, arr);
	printf ("Среднее значение среди чисел всего массива равно %.1f\n", mean);
	printf ("Максимальное значение среди чисел всего массива равно %.1f\n", max);

	return 0;
}

void save_arr (int n, int m, double arr[n][m])
{
	for (int i = 0; i < n; i++) {
		printf ("Введите 5 значений типа double: \n");
		for (int j = 0; j < m; j++)
			while (scanf ("%lf", &arr[i][j]) != 1) {
				while (getchar () != '\n')
					;

				printf ("Ввод некорректен. Повторите ввод\n");
			}
	}
}

void mean_row (int n, const double arr[n])
{
	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	printf ("Среднее значение чисел набора равно = %.1f\n", sum / n);
}

double mean_arr (int n, int m, const double arr[n][m])
{
	double sum = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += arr[i][j];

	return sum / (n * m);
}

double max_arr (int n, int m, const double arr[n][m])
{
	double max = arr[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (max < arr[i][j]) max = arr[i][j];

	return max;
}

void print_arr(int n, int m, const double arr[n][m])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("arr[%d][%d] = %.1f\n", i, j, arr[i][j]);

	printf("\n");
}
/*
$ ./14process_val_arr 
Введите 5 значений типа double: 
1.1 2.2 3.3 4.4 5.5
Введите 5 значений типа double: 
6.6 7.7 8.8 9.9 0.0
Введите 5 значений типа double: 
1.2 3.4 5.6 7.8 9.0
arr[0][0] = 1.1
arr[0][1] = 2.2
arr[0][2] = 3.3
arr[0][3] = 4.4
arr[0][4] = 5.5
arr[1][0] = 6.6
arr[1][1] = 7.7
arr[1][2] = 8.8
arr[1][3] = 9.9
arr[1][4] = 0.0
arr[2][0] = 1.2
arr[2][1] = 3.4
arr[2][2] = 5.6
arr[2][3] = 7.8
arr[2][4] = 9.0

Среднее значение чисел набора равно = 3.3
Среднее значение чисел набора равно = 6.6
Среднее значение чисел набора равно = 5.4
Среднее значение среди чисел всего массива равно 5.1
Максимальное значение среди чисел всего массива равно 9.9
*/