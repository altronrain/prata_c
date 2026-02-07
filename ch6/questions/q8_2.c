/* q8_2.c -- вывод программы
Что выведет следующая программа в случае ввода фразы:

Go west, young man!?

#include <stdio.h>

int main (void)
{
	char ch;

	scanf ("%c", &ch);
	while (ch != 'g')
	{
		printf ("%c", ++ch);
		scanf("%c", &ch);
	}

	return 0;
}

*/
#include <stdio.h>

int main (void)
{
	char ch;

	scanf ("%c", &ch);
	while (ch != 'g')			/* Hp!xftu-!zpvo */
	{
		printf ("%c", ++ch);
		scanf("%c", &ch);
	}

	printf ("\n");

	return 0;
}

/*
$ ./q8_2
Go west, young man!?
Hp!xftu-!zpvo
*/