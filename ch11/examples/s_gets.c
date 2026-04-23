/* s_gets.c  -- использование собственной функции s_gets()

Поведение s_gets:
* отбрасывает часть ввода, не влезающую в буфер
* заменяет символ новой строки на нулевой символ при записи
*/
#include <stdio.h>
#define STLEN 10

char * s_gets (char * st, int n);

int main (void)
{
	char words[STLEN];

	puts ("Введите строки (или пустую строку для выхода из программы):");

	while (s_gets (words, STLEN) != NULL && words[0] != '\0')
		puts (words);

	puts ("Готово.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets (st, n, stdin);

	if (ret_val != NULL) {	/* или просто ret_val, но не рекомендуется */
		while (st[i] != '\n' && st[i] != '\0')
			i++;

		if (st[i] == '\n')
			st[i] = '\0';
		else	/* requires words[i] == '\0' */
			while (getchar () != '\n')
				;
	}

	return ret_val;
}
/*
$ ./s_gets 
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