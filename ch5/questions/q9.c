/* q9.c -- Вывод букв алфавита. Модификация программы из q8.c */
#include <stdio.h>

int main(void)
{
	char c = 'a';

	printf("%5c", c);
	while (c++ < 'g')
		printf("%5c", c);
	printf("\n");

	return 0;
}

/*
$ ./q9
    a    b    c    d    e    f    g

	while (c <= 'g') {
		printf("%5c", c);
		c++;
	}
	printf("\n");

	printf("%5c", c);
	while (c++ < 'g')
		printf("%5c", c);
	printf("\n");
*/