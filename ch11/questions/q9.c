/* q9.c  -- собственная функция s_gets() через указатели

Поведение s_gets:
* отбрасывает часть ввода, не влезающую в буфер
* заменяет символ новой строки на нулевой символ при записи

Функцию s_gets(), определенную в этой главе, можно переписать в форме с использованием
указателей, а не массивов, чтобы исключить из нее переменную i. Сделайте это
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

	ret_val = fgets (st, n, stdin);

	if (ret_val != NULL) {	/* или просто ret_val, но не рекомендуется */
		while (*st != '\n' && *st != '\0')
			st++;

		if (*st == '\n')
			*st = '\0';
		else	/* requires words[i] == '\0' */
			while (getchar () != '\n')
				;
	}

	return ret_val;
}
/*
$ ./q9 
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