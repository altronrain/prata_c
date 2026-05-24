/* 10despace.c -- удаление пробелов из строки

Напишите функцию, которая принимает строку в качестве аргумента и удаляет
из нее все пробелы.
Протестируйте эту функцию в программе, которая использует цикл для чтения
строк до тех пор, пока не будет введена пустая строка. Программа должна
применять эту функцию к каждой входной строке и отображать результат.
*/
#include <stdio.h>
#include <string.h>
#define SIZE 101

char * s_gets (char *st, int n);
void despace (char *str);

int main (void)
{
	char str[SIZE];

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (str, SIZE) && str[0] != '\0') {

		despace (str);

		printf ("Строка без пробелов:\n%s\n", str);

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

void despace (char *str)
{
	char *ptr = str;
	char *end = str;
	int i = 0;

	while (*end != '\0') end++;	/* end = strchr (str, '\0'); */

	while (ptr + i <= end) {

		while (*(ptr + i) == ' ')
			i++;

		*ptr = *(ptr + i);
		ptr++;
	}
}
/*
$ ./10despace 
Введите строку (или пустую строку для выхода из программы):
     ~Booo~     ~BOOOOO~
Строка без пробелов:
~Booo~~BOOOOO~
Введите новую строку (или пустую строку для выхода из программы): 
Luke, you are the greatest jedi!
Строка без пробелов:
Luke,youarethegreatestjedi!
Введите новую строку (или пустую строку для выхода из программы): 
Space rangers 2 is one of the greatest games developed by russians.
Строка без пробелов:
Spacerangers2isoneofthegreatestgamesdevelopedbyrussians.
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/