/* fgetsfputs2.c  -- использование функций fgets() и fputs() */
#include <stdio.h>
#define STLEN 10

int main (void)
{
	char words[STLEN];

	puts ("Введите строки (или пустую строку для выхода из программы):");

	/* Не имеет проблем с буфером. Последовательно читаем и выводим фрагменты по 9 символов */
	while (fgets (words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs (words, stdout);

	puts ("Готово.");

	return 0;
}
/*
$ ./fgetsfputs2
Введите строки (или пустую строку для выхода из программы):
By the way
By the way
gets() function also returns NULL
gets() function also returns NULL
if it encounters end of file situation
if it encounters end of file situation

Готово.
*/