/* q7_2.c -- вывод программы
Что выведет следующая программа:

#include <stdio.h>

int main (void)
{
	int i;
	char ch;

	for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
		printf ("%c", ch);

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	int i;
	char ch;

	for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
		printf ("%c", ch);			/* A C(A+2) G(C+4) M(G+6) */

	printf ("\n");

	return 0;
}

/*
$ ./q7_2 
ACGM
*/