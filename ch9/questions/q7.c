/* q7.c -- определение функции с ошибками

Нет ли ошибок в следующем определении функции?

void salami (num)
{
	int num, count;

	for (count = 1; count <= num; num++)
		printf ("Здравствуйте!\n");
}

*/
#include <stdio.h>

void salami (int num);

int main (void)
{
	salami (5);

	return 0;
}

void salami (int num)
{
	for (int count = 1; count <= num; count++)
		printf ("Здравствуйте!\n");
}

/*
$ ./q7
Здравствуйте!
Здравствуйте!
Здравствуйте!
Здравствуйте!
Здравствуйте!
*/