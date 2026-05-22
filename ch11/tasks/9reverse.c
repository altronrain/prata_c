/* 9reverse.c -- переворачивание строки

Напишите функцию, которая заменяет содержимое указанной строки этой же
строкой, но с обратным порядком следования символов.
Протестируйте функцию в завершенной программе, которая использует цикл
для передачи входных значений созданной функции.
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80

char * s_gets (char *st, int n);
void reverse (char *str);

int main (void)
{
	char str[SIZE];

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (str, SIZE) && str[0] != '\0') {

		reverse (str);

		printf ("Строка с обратным порядком символов:\n%s\n", str);

		puts ("Введите новую строку (или пустую строку для выхода из программы): ");
	}

	puts ("Готово.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets (st, n, stdin);

	if (ret_val) {	/* или просто ret_val, но не рекомендуется */
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

void reverse (char *str)
{
	char tmp;
	char *ptr1 = str;
	char *ptr2;

	while (*ptr1 != '\0') ptr1++;	/* scrch ('\0') - 1 */

	ptr2 = ptr1 - 1;
	ptr1 = str;

	while (ptr2 > ptr1) {
		tmp  = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = tmp;

		ptr1++;
		ptr2--;
	}
}

void reverse_ai (char *str)
{
	char *start = str;
	char *end = str;

	while (*end) end++;		/* find the end of the string */

	while (start < --end) {		/* step back */
		char tmp = *start;

		*start++ = *end;
		*end = tmp;
	}
}
/*
$ ./9reverse 
Введите строку (или пустую строку для выхода из программы):
dataset
Строка с обратным порядком символов:
tesatad
Введите новую строку (или пустую строку для выхода из программы): 
gollum
Строка с обратным порядком символов:
mullog
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/