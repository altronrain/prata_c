/* 4call_quantity.c -- подсчет функцией количества ее вызовов

Напишите и протестируйте в цикле функцию, которая возвращает количество ее вызовов.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func_to_call (void);

int main (void)
{
	int limit;
	int n;

	srand (time (NULL));
	limit = rand () % 20;

	for (n = 0; n < limit; n++)
		printf ("I have been called %d times.\n", func_to_call ());

}

int func_to_call (void)
{
	static int calls = 0;

	calls++;
	return calls;
}
/*
$ ./4call_quantity 
I have been called 1 times.
I have been called 2 times.
I have been called 3 times.
I have been called 4 times.
I have been called 5 times.
I have been called 6 times.
I have been called 7 times.
I have been called 8 times.
I have been called 9 times.

$ ./4call_quantity 
I have been called 1 times.
I have been called 2 times.
I have been called 3 times.
I have been called 4 times.
I have been called 5 times.
*/