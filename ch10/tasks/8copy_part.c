/* 8copy_part.c -- частичное копирование массива

Воспользуйтесь одной из функций копирования из упражнения 2 для копирования
элементов с 3-го по 5-й семиэлементного массива в массив, состоящий из трех
элементов. Саму функцию изменять не нужно; просто подберите правильные фактические
аргументы. (Фактическими аргументами не обязательно должны быть имя массива и его
размер. Ими только должны быть адрес элемента массива и количество обрабатываемых
элементов.)
*/
#include <stdio.h>

void copy_arr (double [], double [], int);
void print_arr(const double [], int, const char *);

int main (void)
{
	double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target[3];


	copy_arr (target, &source[3], 3);
	print_arr (target, 3, "target");

	return 0;
}

void copy_arr (double tgt[], double src[], int n)
{
	for (int i = 0; i < n; i++) {
		tgt[i] = src[i];
	}
}

void print_arr(const double *arr, int n, const char *name)
{
	for (int i = 0; i < n; i++) {
		printf("%s[%d] = %.1f\n", name, i, arr[i]);
	}

	printf("\n");
}
/*
$ ./8copy_part 
target[0] = 4.4
target[1] = 5.5
target[2] = 6.6
*/