/* q7.c -- программа с ошибками

Что неправильно в следующей программе?

#include <stdio.h>
int main(void)
{
	char ch;
	int lc = 0;		/* счетчик строчных символов
	int lc = 0;		/* счетчик прописных символов
	int lc = 0;		/* счетчик других символов

	while ( (ch = getchar()) != '#')
	{
		if ('a' <= ch >= 'z')
			lc++;
		else if (!(ch < 'A') || !(ch > 'Z'))
			uc++;
		oc++;
	}
	printf (%d строчных, %d прописных, %d других, lc, uc, oc);
	return 0;
}
*/
#include <stdio.h>
/* #include <ctype.h> */
int main(void)
{
	char ch;
	int lc = 0;		/* счетчик строчных символов */
	int uc = 0;		/* счетчик прописных символов */
	int oc = 0;		/* счетчик других символов */

	while ( (ch = getchar()) != '#')
	{
		if (ch >= 'a' && ch <= 'z')			/* islower(ch) */
			lc++;
		else if (ch >= 'A' && ch <= 'Z')	/* isupper(ch) */
			uc++;
		else
			oc++;
	}
	printf ("%d строчных, %d прописных, %d других\n", lc, uc, oc);

	return 0;
}

/*
$ ./q7
Kirill, it's time to learn C language, I'm sure!#
32 строчных, 3 прописных, 13 других
*/