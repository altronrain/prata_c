/* sort_str.c  -- считывание строк и их сортировка */
#include <stdio.h>
#include <string.h>
#define SIZE 81		/* лимит на длину строки включая \0 */
#define LIM 20		/* максимальное количество читаемых строк */
#define HALT ""		/* нулевая строка для прекращения ввода */

void stsrt (char *strings[], int num);
char * s_gets (char * st, int n);

int main (void)
{
	char input[LIM][SIZE];		/* массив хранения входных данных */
	char *ptstr[LIM];		/* массив указателей на строки */
	int ct = 0;			/* счетчик ввода */
	int k;				/* счетчик вывода */

	printf ("Enter upto %d strings and they will be sorted.\n", LIM);
	printf ("To stop press Enter at the start of the string.\n");

	while (ct < LIM && s_gets (input[ct], SIZE) && input[ct][0]) {
		ptstr[ct] = input[ct];	/* установка указателей на строки */
		ct++;
	}

	stsrt (ptstr, ct);		/* сортировка "строк" (на самом деле сортируем указатели) */
	puts ("\nSorted list:\n");

	for (k = 0; k < ct; k++)
		puts (ptstr[k]);	/* отсортированные указатели */

	return 0;
}

/* Сортируем указатели на строки, переключая куда они указывают
Это гораздо менее затратно, нежели копировать содержимое input через strcpy() */
void stsrt (char *strings[], int num)
{
	char *temp;

	/* сортировка выбором. поочередное сравнение элементов с первым и так далее */
	for (int top = 0; top < num - 1; top++)
		for (int seek = top + 1; seek < num; seek++)
			if (strcmp (strings[top], strings[seek]) > 0) {
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

char * s_gets (char * st, int n)
{
	char * ret_val, * find;

	ret_val = fgets (st, n, stdin);
	find = strchr (st, '\n');
	if (find)
		*find = '\0';
	else
		while (getchar () != '\n')
			;

	return ret_val;
}
/*
$ ./sort_str 
Enter upto 20 strings and they will be sorted.
To stop press Enter at the start of the string.
Beetles are scary!
World is a terrifying place.
Album costs too much.
Free hugs!
Join our cause.


Sorted list:

Album costs too much.
Beetles are scary!
Free hugs!
Join our cause.
World is a terrifying place.
*/