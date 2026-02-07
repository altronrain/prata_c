/* q8_4.c -- вывод программы
Что выведет следующая программа в случае ввода фразы:

Go west, young man!?

#include <stdio.h>

int main (void)
{
	char ch;

	scanf ("%c", &ch);
	for (ch = '$'; ch != 'g'; scanf("%c", &ch))
		printf ("%c", ch);

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	char ch;

	scanf ("%c", &ch);
	for (ch = '$'; ch != 'g'; scanf("%c", &ch))		/* $o west, yon */
		printf ("%c", ch);

	printf ("\n");

	return 0;
}

/*
$ ./q8_4
Go west, young man!?
$o west, youn
*/