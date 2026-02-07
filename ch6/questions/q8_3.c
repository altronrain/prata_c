/* q8_3.c -- вывод программы
Что выведет следующая программа в случае ввода фразы:

Go west, young man!?

#include <stdio.h>

int main (void)
{
	char ch;

	do {
		scanf ("%c", &ch);
		printf ("%c", ch);
	} while (ch != 'g');

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	char ch;

	do {					/* Go west, young */
		scanf ("%c", &ch);
		printf ("%c", ch);
	} while (ch != 'g');

	printf ("\n");

	return 0;
}

/*
$ ./q8_3
Go west, yong man!?
Go west, yong
*/