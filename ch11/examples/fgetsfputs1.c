/* fgetsfputs1.c  -- использование функций fgets() и fputs() */
#include <stdio.h>
#define STLEN 15

int main (void)
{
	char words[STLEN];

	puts ("Введите строку.");
	fgets (words, STLEN, stdin);	/* sting\n\0 */
	printf ("Ваша строка, выведенная дважды (с помощью puts() и fputs()):\n");
	puts (words);			/* string\n\0 -> string\n\n */
	fputs (words, stdout);
	puts ("Введите еще одну строку.");
	fgets (words, STLEN, stdin);
	printf ("Ваша строка, выведенная дважды (с помощью puts() и fputs()):\n");
	puts (words);
	fputs (words, stdout);
	puts ("Готово.");

	return 0;
}
/*
$ ./fgetsfputs1 
Введите строку.
cheesecake
Ваша строка, выведенная дважды (с помощью puts() и fputs()):
cheesecake

cheesecake
Введите еще одну строку.
Once upon a time in a far-far-away galaxy...
Ваша строка, выведенная дважды (с помощью puts() и fputs()):
Once upon a ti
Once upon a tiГотово.
*/