/* bounds.c -- выход за пределы массива */
#include <stdio.h>
#define SIZE 4

int main (void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	int i;

	printf ("value1 = %d, value2 = %d\n", value1, value2);

	for (i = -1; i <= SIZE; i++)
		arr[i] = 2 * i + 1;

	for (i = -1; i < 7; i++)
		printf ("%2d %d\n", i, arr[i]);

	printf ("value1 = %d, value2 = %d\n", value1, value2);
	printf ("адрес arr[-1]: %p\n", &arr[-1]);
	printf ("адрес  arr[4]: %p\n", &arr[4]);
	printf ("адрес  value1: %p\n", &value1);
	printf ("адрес  value2: %p\n", &value2);

	return 0;
}

/*
$ ./bounds 
value1 = 44, value2 = 88
-1 -1
 0 1
 1 3
 2 5
 3 7
 4 9
 5 0
 6 44
value1 = 44, value2 = -1
адрес arr[-1]: 0x7ffcddde732c
адрес  arr[4]: 0x7ffcddde7340
адрес  value1: 0x7ffcddde7348
адрес  value2: 0x7ffcddde732c
*/

/*
На gcc (Debian 14.2.0-19) 14.2.0 адрес arr[-1] совпал с value2 и значение переменной изменилось
Выход за пределы массива -- UB и никак не регламентируется. Такая программа может:
* отработать корректно (маловероятно)
* отработать странно
* аварийно завершиться

результат не гарантирован
*/