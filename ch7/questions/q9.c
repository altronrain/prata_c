/* q9.c -- вывод программы

Что выведет следующая программа при указанном вводе?
q
c
h
b

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

/*
При вводе будет получен результат:

Шаг 1
Шаг 2
Шаг 3
Шаг 1
Шаг 1
Шаг 3
Шаг 1
Готово!

$ ./q9 
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