/* 8array_init_show.c  -- инициализация и вывод массива

Ниже приведена часть программы:

#include <stdio.h>
#include <stdlib.h>

int *make_array (int elem, int val);
void show_array (const int ar[], int n);

int main (void)
{
	int *pa;
	int size;
	int value;

	printf ("Введите количество элементов: ");

	while (scanf ("%d", &size) == 1 && size > 0) {
		printf ("Введите значение для инициализации: ");
		scanf ("%d", &value);
		pa = make_array (size, value);

		if (pa) {
			show_array (pa, size);
			free (pa);
		}

		printf ("Введите количество элементов (<1 для завершения): ");
	}

	printf ("Программа завершена.\n");

	return 0;
}

Завершите программу, предоставив определение функций make_array() и show_array().
Функция make_array() принимает два аргумента. Первый аргумент -- количество элементов
в массиве значений int, а второй аргумент -- значение, которое должно быть присвоено
каждому элементу массива. Эта функция использует malloc() для создания массива подходящего
размера, присваивает каждому элементу заданное значение и возвращает указатель на массив.

Функция show_array() отображает содержимое массива по восемь элементов в строке
*/
#include <stdio.h>
#include <stdlib.h>

int *make_array (int elem, int val);
void show_array (const int ar[], int n);

int main (void)
{
	int *pa;
	int size;
	int value;

	printf ("Введите количество элементов: ");

	while (scanf ("%d", &size) == 1 && size > 0) {
		printf ("Введите значение для инициализации: ");
		scanf ("%d", &value);
		pa = make_array (size, value);

		if (pa) {
			show_array (pa, size);
			free (pa);
		}

		printf ("Введите количество элементов (<1 для завершения): ");
	}

	printf ("Программа завершена.\n");

	return 0;
}

int *make_array (int elem, int val)
{
	int *pa;
	int i;

	pa = malloc (elem * sizeof (int));

	for (i = 0; i < elem; i++)
		pa[i] = val;

	return pa;
}

void show_array (const int *ar, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf ("\t%d", ar[i]);

		if ((i + 1) % 8 == 0)
			printf ("\n");
	}

	printf ("\n");
}
/*
$ ./8array_init_show 
Введите количество элементов: 10
Введите значение для инициализации: 4
        4       4       4       4       4       4       4       4
        4       4
Введите количество элементов (<1 для завершения): 7
Введите значение для инициализации: 3
        3       3       3       3       3       3       3
Введите количество элементов (<1 для завершения): 0
Программа завершена.
*/