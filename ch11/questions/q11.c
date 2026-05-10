/* q11.c  -- собственная функция s_gets() с применением strchr()

Поведение s_gets:
* отбрасывает часть ввода, не влезающую в буфер
* заменяет символ новой строки на нулевой символ при записи

Функцию s_gets(), определенную в этой главе, можно переписать с использованием
функции strchr() вместо цикла while для обнаружения символа новой строки. Сделайте это
*/
#include <stdio.h>
#include <string.h>
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
	char *ret_val, *find;

	ret_val = fgets (st, n, stdin);
	if (ret_val) {
		find = strchr (st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar () != '\n')
				;
	}

	return ret_val;
}
/*
$ ./q11 
Введите строки (или пустую строку для выхода из программы):
this
this
program don't
program d
like too long strings
like too 
as you can see, Luke
as you ca

Готово.
*/