/* 11double_arr.c -- удвоение значений элементов массива

Напишите программу, которая объявляет массив 3x5 значений типа int и инициализирует его
значениями по вашему выбору. Программа должна вывести эти значения, удвоить все значения,
после чего вывести новые значения. Напишите одну функцию для вывода значений и еще одну
для удваивания значений. В качестве аргументов функции должны принимать имя массива и
количество строк.
*/
#include <stdio.h>
#define SIZE 5

void double_arr (int [][SIZE], int);
void print_arr(const int [][SIZE], int);

int main (void)
{
	int source[3][SIZE] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0},
		{10, 20, 30, 40, 50}
	};

	print_arr (source, 3);
	double_arr(source, 3);
	print_arr (source, 3);

	return 0;
}

void double_arr (int arr[][SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < SIZE; j++)
		arr[i][j] = arr[i][j] * 2;
}

void print_arr(const int (*arr)[SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < SIZE; j++)
			printf("source[%d][%d] = %d\n", i, j, arr[i][j]);

	printf("\n");
}
/*
$ ./11double_arr 
source[0][0] = 1
source[0][1] = 2
source[0][2] = 3
source[0][3] = 4
source[0][4] = 5
source[1][0] = 6
source[1][1] = 7
source[1][2] = 8
source[1][3] = 9
source[1][4] = 0
source[2][0] = 10
source[2][1] = 20
source[2][2] = 30
source[2][3] = 40
source[2][4] = 50

source[0][0] = 2
source[0][1] = 4
source[0][2] = 6
source[0][3] = 8
source[0][4] = 10
source[1][0] = 12
source[1][1] = 14
source[1][2] = 16
source[1][3] = 18
source[1][4] = 0
source[2][0] = 20
source[2][1] = 40
source[2][2] = 60
source[2][3] = 80
source[2][4] = 100
*/