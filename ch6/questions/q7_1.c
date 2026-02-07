/* q7_1.c -- вывод программы
Что выведет следующая программа:

#include <stdio.h>

int main (void)
{
	int i = 0;

	while (++i < 4)
		printf ("Hi! ");
	do
		printf ("Bye! ");
	while (i++ < 8);

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	int i = 0;

	while (++i < 4)
		printf ("Hi! ");	/* Hi! Hi! Hi! */
	do						/* 1    2   3  */
		printf ("Bye! ");	/* Bye! Bye! Bye! Bye! Bye! */
	while (i++ < 8);		/* 4(5)  5(6) 6(7) 7(8) 8(9)*/

	printf ("\n");

	return 0;
}

/*
$ ./q7_1 
Hi! Hi! Hi! Bye! Bye! Bye! Bye! Bye!
*/