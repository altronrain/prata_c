/* q2.c  -- что делает программа*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
	int ch;
	FILE *fp;

	if (argc < 2)
		exit (EXIT_FAILURE);

	if ((fp = fopen (argv[1], "r")) == NULL)
		exit (EXIT_FAILURE);

	while ((ch = getc (fp)) != EOF)
		if (isdigit (ch))
			putchar (ch);

	fclose (fp);

	return 0;
}

/*
Выводит все цифры из указанного файла. Не помешал бы еще перевод строки.

$ ./q2 q2_test.txt 
3003321
*/