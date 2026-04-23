/* fgets.c  -- использование функции fgets()

Отбрасывание остальной части ввода, не влезающей в буфер
*/
#include <stdio.h>
#define STLEN 10

int main (void)
{
	char words[STLEN];
	int i;

	puts ("Введите строки (или пустую строку для выхода из программы):");

	while (fgets (words, STLEN, stdin) != NULL && words[0] != '\n') {
		i = 0;

		while (words[i] != '\n' && words[i] != '\0')
			i++;

		/* если считанная строка меньше STLEN то заменяем \n на \0 */
		if (words[i] == '\n')
			words[i] = '\0';
		else	/* requires words[i] == '\0' */
			while (getchar () != '\n')
				;

		puts (words);
	}

	puts ("Готово.");

	return 0;
}
/*
$ ./fgets
Введите строки (или пустую строку для выхода из программы):
this
this
program don't
program d
like too long strings
like too 
but not stops
but not s
on stumbling accross such strings
on stumbl

Готово.
*/