/* 11rowcalc.c  -- функции работы со строками */
#include <stdio.h>
#include <string.h>
#include "11rowcalc.h"

/* Вывод строк в том порядке, в котором они были записаны */
void print_rows (const char str[][SIZE], int n)
{
	puts ("\nИзначальный список строк:\n");

	for (int i = 0; i < n; i++)
		puts (str[i]);

	puts ("\n");
}

/* Сортируем указатели на строки, переключая куда они указывают
Это гораздо менее затратно, нежели копировать содержимое input через strcpy() */
void sort_ascii (const char str[][SIZE], int n)
{
	const char *ptstr[n]; /* Массив указателей на строки */
	const char *temp;

	for (int i = 0; i < n; i++)
		ptstr[i] = str[i];	/* установка указателей на строки */

	/* сортировка выбором. поочередное сравнение элементов с первым и так далее */
	for (int top = 0; top < n - 1; top++)
		for (int seek = top + 1; seek < n; seek++)
			if (strcmp (ptstr[top], ptstr[seek]) > 0) {
				temp = ptstr[top];
				ptstr[top] = ptstr[seek];
				ptstr[seek] = temp;
			}

	puts ("\nОтсортированный по символам ASCII список:\n");

	for (int k = 0; k < n; k++)
		puts (ptstr[k]);

	puts ("\n");
}

void sort_length (const char str[][SIZE], int n)
{
	const char *ptstr[n]; /* Массив указателей на строки */
	const char *temp;

	for (int i = 0; i < n; i++)
		ptstr[i] = str[i];	/* установка указателей на строки */

	for (int top = 0; top < n - 1; top++)
		for (int seek = top + 1; seek < n; seek++)
			if (strlen (ptstr[top]) > strlen (ptstr[seek])) {
				temp = ptstr[top];
				ptstr[top] = ptstr[seek];
				ptstr[seek] = temp;
			}

	puts ("\nОтсортированный по длине строк список:\n");

	for (int k = 0; k < n; k++)
		puts (ptstr[k]);

	puts ("\n");
}

void sort_fwlength (const char str[][SIZE], int n)
{
	const char *ptstr[n]; /* Массив указателей на строки */
	const char *temp;
	int len_a = 0;
	int len_b = 0;

	for (int i = 0; i < n; i++)
		ptstr[i] = str[i];	/* установка указателей на строки */

	for (int top = 0; top < n - 1; top++)
		for (int seek = top + 1; seek < n; seek++) {
			len_a = strchr (ptstr[top], ' ') - ptstr[top];
			len_b = strchr (ptstr[seek], ' ') - ptstr[seek];

			if (len_a > len_b) {
				temp = ptstr[top];
				ptstr[top] = ptstr[seek];
				ptstr[seek] = temp;
			}
		}

	puts ("\nОтсортированный по длине строк список:\n");

	for (int k = 0; k < n; k++)
		puts (ptstr[k]);

	puts ("\n");
}