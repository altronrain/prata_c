/* for_cube.c -- построение таблицы кубов с применением цикла for */
#include <stdio.h>

int main(void)
{
	int num;

	printf ("\tn\tn в кубе\n");
	for (num = 1; num <= 10; num++)
		printf ("\t%d\t%5d\n", num, num * num * num);

	return 0;
}

/*
$ ./for_cube 
        n       n в кубе
        1           1
        2           8
        3          27
        4          64
        5         125
        6         216
        7         343
        8         512
        9         729
        10       1000
*/