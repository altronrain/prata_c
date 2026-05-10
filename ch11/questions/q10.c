/* q10.c  -- собственная функция str_len()

Функция strlen() принимает указатель на строку в качестве аргумента и
возвращает длину строки. Напишите свою версию этой функции.
*/
#include <stdio.h>
#include <string.h>
#define STLEN 51

char * s_gets (char * st, int n);
size_t str_len (const char * st);

int main (void)
{
	char words[STLEN];

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (words, STLEN) && words[0] != '\0')
		printf ("Длина введенной строки: %zu\n", str_len (words));

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

size_t str_len (const char * st)
{
	const char *ptr = st;
	unsigned i = 0;

	while (*ptr++) i++;

	return i;
}
/*
19:09 $ ./q10 
Введите строку (или пустую строку для выхода из программы):
test
Длина введенной строки: 4
program
Длина введенной строки: 7
Cool function!
Длина введенной строки: 14

Готово.
*/