/* q12.c  -- поиск пробела в строке (свой вариант strchr())

Разработайте функцию, которая принимает указатель на строку в качестве
аргумента и возвращает указатель на первый символ пробела, расположенный в
указанной позиции внутри строки или после нее. Функция должна возвращать
нулевой указатель, если пробелы не найдены.
*/
#include <stdio.h>
#include <string.h>
#define STLEN 51

char * s_gets (char * st, int n);
const char * strspace (const char * st);

int main (void)
{
	char words[STLEN];
	const char *ptr;

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (words, STLEN) && words[0] != '\0')
		if ((ptr = strspace (words)))
			printf ("Вот пробел из строки: '%c'\n", *ptr);
		else
			printf ("В введенной строке пробела нет.\n");

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

const char * strspace (const char * st)		/* test\0 */
{
	const char *ptr = st;			/* ptr = t */

	while (*ptr != ' ' && *ptr != '\0')
		ptr++;

	if (*ptr)
		return ptr;
	else {
		return NULL;
	}
}
/*
$ ./q12
Введите строку (или пустую строку для выхода из программы):
test
В введенной строке пробела нет.
big string
Вот пробел из строки: ' '
 
Готово.
*/