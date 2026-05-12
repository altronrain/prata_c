/* 5find_symbol.c  -- поиск символа в строке (дублирует strchr())

Разработайте и протестируйте функцию, которая ищет в переданной в первом
параметре строке первое вхождение символа, заданного во втором параметре.
Функция должна возвратить указатель на этот символ, если он найден, и ноль
в противном случае. (Поведение этой функции дублирует работу библиотечной
функции strchr().)
Протестируйте функцию в завершенной программе, которая использует цикл для
передачи входных значений созданной функции.
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 80

char * s_gets (char * st, int n);
char * fchar  (char * st, char c);

int main (void)
{
	char str[SIZE];
	int ch, res;
	char *ptr;


	puts ("Введите строки (или пустую строку для выхода из программы):");

	while (s_gets (str, SIZE) && str[0] != '\0') {

		puts ("Введите искомый символ: ");
		ch = getchar ();

		while ((res = getchar()) != EOF && res != '\n')	/* очистка ввода */
			;

		if (ch != EOF) {
			ptr = fchar (str, ch);
			printf ("Адрес и значение искомого символа в строке: %p, %c\n", ptr, *ptr);
		}

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

char * fchar (char *st, char c)
{
	char *ptr = st;

	while (*ptr != '\0') {

		if (*ptr == c)
			return ptr;
		ptr++;
	}

	return 0;
}
/*
$ ./5find_symbol 
Введите строки (или пустую строку для выхода из программы):
Sometimes better to think before action
Введите искомый символ: 
e
Адрес и значение искомого символа в строке: 0x7ffd04e9df53, e
Введите новую строку (или пустую строку для выхода из программы): 
Luke, this is cool!
Введите искомый символ: 
o
Адрес и значение искомого символа в строке: 0x7ffd04e9df5f, o
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/