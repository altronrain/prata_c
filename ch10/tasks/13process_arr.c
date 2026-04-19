/* 13process_arr.c -- вычисления с массивами

Напишите программу, которая предлагает пользователю ввести три набора по пять чисел double.
(Для простоты можете полагать, что пользователь отвечает корректно и не вводит нечисловые данные.)
Программа должна выполнять все перечисленные ниже действия:

а) Хранить информацию в массиве 3x5
б) Вычислять среднее для каждого набора из пяти значений
в) Вычислять среднее для всех значений
г) Определять наибольшее из 15 значений
д) Выводить результат на экран

Каждая значительная задача должна решаться посредством отдельной функции с использованием
традиционного в языке C подхода к обработке массивов. Выполните задачу б) с помощь. функции,
которая вычисляет и возвращает среднее значение одномерного массива; воспользуйтесь циклом
для вызова этой функции три раза. Функции, реализующие остальные задачи, должны принимать в
качестве аргумента массив целиком, а функции, выполняющие задачи в) и г), должны возвращать
ответ в вызывающую программу.
*/
#include <stdio.h>
#define ROWS 3
#define COLS 5

void save_arr (double [][COLS], int);
void mean_row (const double [], int);
double mean_arr (const double [][COLS], int);
double max_arr  (const double [][COLS], int);
void print_arr(const double [][COLS], int);

int main (void)
{
	double arr[ROWS][COLS];
	double mean, max;

	save_arr (arr, ROWS);
	print_arr(arr, ROWS);
	for (int i = 0; i < ROWS; i++)
		mean_row (arr[i], COLS);
	mean = mean_arr (arr, COLS);
	max = max_arr (arr, COLS);
	printf ("Среднее значение среди чисел всего массива равно %.1f\n", mean);
	printf ("Максимальное значение среди чисел всего массива равно %.1f\n", max);

	return 0;
}

void save_arr (double arr[][COLS], int n)
{
	for (int i = 0; i < n; i++) {
		printf ("Введите 5 значений типа double: \n");
		for (int j = 0; j < COLS; j++)
			while (scanf ("%lf", &arr[i][j]) != 1) {
				while (getchar () != '\n')
					;

				printf ("Ввод некорректен. Повторите ввод\n");
			}
	}
}

void mean_row (const double arr[], int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	printf ("Среднее значение чисел набора равно = %.1f\n", sum / n);
}

double mean_arr (const double arr[][COLS], int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < COLS; j++)
			sum += arr[i][j];

	return sum / (n * COLS);
}

double max_arr (const double arr[][COLS], int n)
{
	double max = arr[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < COLS; j++)
			if (max < arr[i][j]) max = arr[i][j];

	return max;
}

void print_arr(const double (*arr)[COLS], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < COLS; j++)
			printf("arr[%d][%d] = %.1f\n", i, j, arr[i][j]);

	printf("\n");
}
/*
$ ./13process_arr 
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
Среднее значение среди чисел всего массива равно 3.1
Максимальное значение среди чисел всего массива равно 9.9
*/