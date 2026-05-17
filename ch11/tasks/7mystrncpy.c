/* 6symbol_presence.c  -- копирование строк (дублирует strncpy())

Функция strncpy(s1,s2,n) копирует в точности n символов из строки s2 в строку s1,
при необходимости усекая s2 или дополняя ее нулевыми символами. Целевая строка
может не содержать завершающего нулевого символа, если длина строки s2 равна
или больше n. Функция возвращает строку s1. Напишите свою версию этой функции
и назовите ее mystrncpy().
Протестируйте функцию в завершенной программе, которая использует цикл
для передачи входных значений созданной функции.
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80

char * s_gets (char * st, int n);
char * mystrncpy (char *tgt, const char *src, int n);

int main (void)
{
	char str1[SIZE];
	char str2[SIZE];
	int num, res;

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (str1, SIZE) && str1[0] != '\0') {

		puts ("Введите вторую строку (или пустую строку для выхода из программы):");
		if (s_gets (str2, SIZE) == NULL || str2[0] == '\0') {
			break;
		}

		puts ("Введите количество символов для копирования:");
		while (scanf ("%d", &num) != 1) {

			while ((res = getchar()) != EOF && res != '\n')	/* очистка ввода */
				;

			puts ("Корректно повторите ввод числа:");
		}

		getchar ();	/* scanf оставляет \n */

		mystrncpy (str1, str2, num);
		printf ("Получена следующая строка:\n%s\n", str1);

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

char * mystrncpy (char *src, const char *tgt, int n)
{
	char *ptr1;
	const char *ptr2;
	int i = 0;

	ptr1 = src;
	ptr2 = tgt;

	while (i < n && *ptr2 != '\0') {
		*ptr1++ = *ptr2++;
		i++;
	}

	while (i < n) {
		*ptr1++ = '\0';
		i++;
	}

	return src;
}
/*
$ ./7mystrncpy 
Введите строку (или пустую строку для выхода из программы):
Sometimes it is better to think
Введите вторую строку (или пустую строку для выхода из программы):
Before taking an action
Введите количество символов для копирования:
25
Получена следующая строка:
Before taking an action
Введите новую строку (или пустую строку для выхода из программы): 
Luke, this is cool!
Введите вторую строку (или пустую строку для выхода из программы):
Yoda says peacfully
Введите количество символов для копирования:
4
Получена следующая строка:
Yoda, this is cool!
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/