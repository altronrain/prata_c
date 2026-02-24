/* q6_a.c -- вывод фрагментов программы для указанного ввода

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

	while ((ch = getchar ()) != 'i')
		putchar (ch);					/* if you qu */

	printf ("\n");

	return 0;
}

/*
$ ./q6_a 
If you quit, I will.
If you qu
*/