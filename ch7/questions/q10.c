/* q10.c -- переписать программу

Перепишите программу из вопроса 9 так, чтобы она сохранила свое поведение,
но в ней не использовались операторы continue и goto.

#include <stdio.h>
int main(void)
{
	char ch;

	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf ("Шаг 1\n");
		if (ch == 'c')
			continue;
		else if (ch == 'b')
			break;
		else if (ch == 'h')
			goto laststep;
		printf ("Шаг 2\n");
	laststep: printf ("Шаг 3\n");
	}
	printf ("Готово\n");
	return 0;
}
*/
#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != '#')
	{
		if (ch != '\n') {
			printf ("Шаг 1\n");
			if (ch != 'c') {
				if (ch == 'b')
					break;
				else if (ch != 'h')
					printf ("Шаг 2\n");
				printf ("Шаг 3\n");
			}
		}
	}

	printf ("Готово\n");

	return 0;
}

/*
$ ./q10
q
Шаг 1
Шаг 2
Шаг 3
c
Шаг 1
h
Шаг 1
Шаг 3
b
Шаг 1
Готово
*/