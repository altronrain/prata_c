/* for_wild.c -- выражение в третьей части объявления цикла for */
#include <stdio.h>

int main(void)
{
	int x;
	int y = 55;

	for (x = 1; y <= 75; y = (++x * 5) + 50)	/* Шаг 1: 1, 55 -- третья часть выполняется после тела цикла */
		printf ("%10d %10d\n", x, y);

	return 0;
}

/*
$ ./for_wild 
         1         55
         2         60
         3         65
         4         70
         5         75
*/