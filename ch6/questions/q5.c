/* q5.c -- программа с ошибками
Приведенная ниже программа не идеальна. Какие ошибки вы можете найти?

#include <stdio.h>
int main(void)
{
	int i, j, list(10);
	for (i = 1, i <=10, i++)
	{
		list[i] = 2*i + 3;
		for (j = 1, j >= i, j++)
			printf (" %d", list[j]);
		printf ("\n");
	}
}

*/
#include <stdio.h>

int main(void)
{
	int i, j, list[10];

	for (i = 0; i < 10; i++)
	{
		list[i] = 2*i + 3;
		for (j = 0; j <= i; j++)
			printf (" %d", list[j]);

		printf ("\n");
	}

	return 0;
}

/*
$ ./q5
 3
 3 5
 3 5 7
 3 5 7 9
 3 5 7 9 11
 3 5 7 9 11 13
 3 5 7 9 11 13 15
 3 5 7 9 11 13 15 17
 3 5 7 9 11 13 15 17 19
 3 5 7 9 11 13 15 17 19 21
*/