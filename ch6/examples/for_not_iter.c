/* for_not_iter.c -- условие не по количеству итераций */
#include <stdio.h>

int main(void)
{
	int num;

	printf ("\tn\tn в кубе\n");
	for (num = 1; num * num * num <= 216; num++)
		printf ("\t%d\t%5d\n", num, num * num * num);

	return 0;
}

/*
$ ./for_not_iter 
        n       n в кубе
        1           1
        2           8
        3          27
        4          64
        5         125
        6         216
*/