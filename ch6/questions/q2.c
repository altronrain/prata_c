/* q2.c -- вывод значений value
При условии, что переменная value имеет тип int, определите, какой вывод
будет получен в результате выполнения следующего цикла:

for (value = 36; value > 0; value /= 2)
	printf ("%3d", value);

Какие проблемы могли бы возникнуть, если бы переменная value имела тип
double вместо int?
*/
#include <stdio.h>

int main(void)
{
	int value;

	for (value = 36; value > 0; value /= 2)
		printf ("%3d", value);

	printf ("\n");

	return 0;
}

/* Цикл выполнялся бы бесконечно, имей value тип double */

/*
$ ./q2 
 36 18  9  4  2  1
*/