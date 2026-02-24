/* q6_b.c -- вывод фрагментов программы для указанного ввода

a.	If you quit, I will.[enter]

	while ((ch = getchar()) != 'i')
		putchar (ch);

b.	Harhar[enter]

	while ((ch = getchar ()) != '\n')
	{
	putchar (ch++);
		putchar (++ch);
	}

*/
#include <stdio.h>

int main(void)
{
	int ch;

	while ((ch = getchar ()) != '\n')
	{
	putchar (ch++);
		putchar (++ch);					/* HJacrthjacrt */
	}

	printf ("\n");

	return 0;
}

/*
$ ./q6_b
Harhar
HJacrthjacrt
*/