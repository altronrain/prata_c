/* q8.c -- Что выведет эта программа

#include <stdio.h>
#define TEN 10

int main(void)
{
	int n = 0;

	while (n++ < TEN)
		printf("%5d", n);		1 2 3 4 5 6 7 8 9 10
	printf("\n");

	return 0;
}

*/
#include <stdio.h>
#define TEN 10

int main(void)
{
	int n = 0;

	while (n++ < TEN)
		printf("%5d", n);
	printf("\n");

	return 0;
}

/*
$ ./q8
    1    2    3    4    5    6    7    8    9   10

	while (n++ < TEN):    1    2    3    4    5    6    7    8    9   10
	while (++n < TEN):    1    2    3    4    5    6    7    8    9

	Внутрь цикла так и так попадает уже увеличенная переменная, имеет значение на этапе сравнения
*/