/* 3symbols.c  -- вывод последовательности

Воспользуйтесь вложенными циклами, чтобы написать программу, которая выводит следующую
последовательность символов:

F
FE
FED
FEDC
FEDCB
FEDCBA

*/
#include <stdio.h>

int main(void)
{
	char ch;
	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0, ch = 'F'; j <= i; j++, ch--)
			printf ("%c", ch);
		printf ("\n");
	}

	return 0;
}

/*
$ ./3symbols 
F
FE
FED
FEDC
FEDCB
FEDCBA
*/