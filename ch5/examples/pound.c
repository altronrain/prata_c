/* pound.c  -- определение функций с аргументами */
#include <stdio.h>

void pound (int n);		/* объявление прототипа фукнкции по стандарту ANSI C (C90) */

int main (void)
{
	int times = 5;
	char ch = '!';		/* ASCII: 33 */
	float f = 6.0f;

	pound (times);		/* аргумент типа int */
	pound (ch);			/* эквивалентно pound ((int) ch) */
	pound (f);			/* эквивалентно pound ((int) f) */

	return 0;
}

void pound (int n)		/* объявление функции в стиле ANSI C (C90) */
{
	while (n-- > 0)
		printf ("#");
	printf ("\n");
}

/*
$ ./pound 
#####
#################################
######
*/