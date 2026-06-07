/* forc99.c  -- правила для блоков в C99 */
#include <stdio.h>

int main (void)
{
	int n = 8;

	printf ("Первоначально n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
		printf ("Цикл 1: n = %d по адресу %p\n", n, &n);
	printf ("После цикла 1 n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
	{
		printf ("Индекс цикла 2: n = %d по адресу %p\n", n, &n);
		int n = 6;
		printf ("Цикл 2: n = %d по адресу %p\n", n, &n);
		n++;
	}
	printf ("После цикла 2 n = %d по адресу %p\n", n, &n);

	return 0;
}
/*
$ ./forc99 
Первоначально n = 8 по адресу 0x7ffc8abd40ec
Цикл 1: n = 1 по адресу 0x7ffc8abd40e8
Цикл 1: n = 2 по адресу 0x7ffc8abd40e8
После цикла 1 n = 8 по адресу 0x7ffc8abd40ec
Индекс цикла 2: n = 1 по адресу 0x7ffc8abd40e4
Цикл 2: n = 6 по адресу 0x7ffc8abd40e0
Индекс цикла 2: n = 2 по адресу 0x7ffc8abd40e4
Цикл 2: n = 6 по адресу 0x7ffc8abd40e0
После цикла 2 n = 8 по адресу 0x7ffc8abd40ec
*/