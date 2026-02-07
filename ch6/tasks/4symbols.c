/* 4symbols.c  -- вывод последовательности

Воспользуйтесь вложенными циклами, чтобы написать программу, которая выводит следующую
последовательность символов:

A
BC
DEF
GHIJ
KLMNO
PQRSTU

*/
#include <stdio.h>

int main(void)
{
	char ch = 'A';
	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0; j <= i; j++, ch++)
			printf ("%c", ch);
		printf ("\n");
	}

	return 0;
}

/*
$ ./4symbols 
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/