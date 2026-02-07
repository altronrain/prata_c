/* q11.c -- программа с ошибками
Кое-кому нравится считать двойками, пожтому он написал программу, которая
создает массив и заполняет его четными числами 2, 4, 6, 8 и т. д.
Если ли ошибки в этой программе?

#include <stdio.h>
#define SIZE 8

int main(void)
{
	int by_twos[SIZE];
	int index;

	for (index = 1; index <= SIZE; index++)
		by_twos[index] = 2 * index;
	for (index = 1; index <= SIZE; index++)
		printf ("%d", by_twos);
	printf ("\n");

	return 0;
}

*/
#include <stdio.h>
#define SIZE 8

int main(void)
{
	int by_twos[SIZE];
	int index;

	for (index = 0; index < SIZE; index++)
		by_twos[index] = 2 * (index + 1);
	for (index = 0; index < SIZE; index++)
		printf ("%d ", by_twos[index]);
	printf ("\n");

	return 0;
}

/*
$ ./q11
2 4 6 8 10 12 14 16
*/