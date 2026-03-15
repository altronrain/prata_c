/* more_data.c  -- инициализированный массив с большим числом элементов */
#include <stdio.h>
#define SIZE 4

int main (void)
{
	int some_data[SIZE] = {1492, 1066, 1267, 1821, 1665};	/* вызывает ошибку компиляции */
	int i;

	printf ("%2s%14s\n", "i", "no_data[i]");

	for (i = 0; i < SIZE; i++)
		printf ("%2d%14d\n", i, some_data[i]);

	return 0;
}

/*
$ gcc more_data.c -o more_data
more_data.c: In function ‘main’:
more_data.c:7:56: warning: excess elements in array initializer
    7 |         int some_data[SIZE] = {1492, 1066, 1267, 1821, 1665};
      |                                                        ^~~~
more_data.c:7:56: note: (near initialization for ‘some_data’)
*/