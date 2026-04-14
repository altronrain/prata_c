/* 2copy_arr.c -- копирование массивов

Напишите программу, которая инициализирует массив значений типа double и затем
копирует его содержимое в три других массива. (Все четыре массива должны быть
объявлены в главной программе.)

* Для создания первой копии воспользуйтесь функцией, в которой применяется форма записи с массивами.
* Для создания второй и третьей копии воспользуйтесь функцией, в которой применяется форма записи 
  с указателями и их инкрементирование.

Первые две функции должны принимать в качестве аргументов:

* имя целевого массива
* имя исходного массива
* количество элементов, подлежащих копированию

Третья функция должна принимать в качестве аргументов:

* имя целевого массива
* имя исходного массива
* указатель на элемент, следующий за последним элементом в исходном массиве.

Пример объявлений и вызовов функций:

double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];

copy_arr (target1, source, 5);
copy_ptr (target2, source, 5);
copy_ptrs(target3, source, source + 5);
*/
#include <stdio.h>

void copy_arr (double [], double [], int);
void copy_ptr (double [], double [], int);
void copy_ptrs(double [], double *start, double *end);

int main (void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr (target1, source, 5);
	printf ("\n");
	copy_ptr (target2, source, 5);
	printf ("\n");
	copy_ptrs(target3, source, source + 5);

	return 0;
}

void copy_arr (double tgt[], double src[], int n)
{
	for (int i = 0; i < n; i++) {
		tgt[i] = src[i];
		printf ("target1[%d] = %.1f\n", i, tgt[i]);
	}
}

void copy_ptr (double *tgt, double *src, int n)
{
	for (int i = 0; i < n; i++) {
		*(tgt + i) = *(src + i);
		printf ("target2[%d] = %.1f\n", i, *(tgt + i));
	}
}

void copy_ptrs (double *tgt, double *start, double *end)
{
	double *ptr = tgt;

	while (start < end) {
		*tgt = *start;
		printf ("target2[%d] = %.1f\n", tgt - ptr, *tgt);

		start++;
		tgt++;
	}
}
/*
$ ./2copy_arr 
target1[0] = 1.1
target1[1] = 2.2
target1[2] = 3.3
target1[3] = 4.4
target1[4] = 5.5

target2[0] = 1.1
target2[1] = 2.2
target2[2] = 3.3
target2[3] = 4.4
target2[4] = 5.5

target2[0] = 1.1
target2[1] = 2.2
target2[2] = 3.3
target2[3] = 4.4
target2[4] = 5.5
*/