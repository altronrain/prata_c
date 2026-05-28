/* 15atoi.c -- классификатор символов для atoi()

Для подготовки реализации функции atoi() используйте функции классификации
символов. Эта версия должна возвращать значение 0, если строка ввода не
является полностью числовой.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 101

int strnum (char *str);
char * s_gets (char * st, int n);

int main (void)
{
	char str[SIZE];
	int num;

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (str, SIZE) && str[0] != '\0') {

		if (strnum (str)) {
			puts ("Строка подходит для выполнения atoi()");
			num = atoi (str);
			printf ("Получено число: %d\n", num);
		}
		else
			puts ("Строка не является полностью числовой");

		puts ("Введите новую строку (или пустую строку для выхода из программы): ");
	}

	puts ("Готово.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;
	int c;

	ret_val = fgets (st, n, stdin);

	if (ret_val) {
		while (st[i] != '\n' && st[i] != '\0')
			i++;

		if (st[i] == '\n')
			st[i] = '\0';
		else
			while  ((c = getchar ()) != '\n' && c != EOF)
				;
	}

	return ret_val;
}

int strnum (char *str)
{
	char *ptr;

	for (ptr = str; *ptr != '\0'; ptr++)
		if (! isdigit (*ptr))
			return 0;

	return 1;
}
/*
$ ./15atoi 
Введите строку (или пустую строку для выхода из программы):
123buddy
Строка не является полностью числовой
Введите новую строку (или пустую строку для выхода из программы): 
6295612
Строка подходит для выполнения atoi()
Получено число: 6295612
Введите новую строку (или пустую строку для выхода из программы): 
ghun45
Строка не является полностью числовой
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/