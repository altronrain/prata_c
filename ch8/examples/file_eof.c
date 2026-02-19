/* file_eof.c -- открывает файл и отображает его содержимое */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	FILE *fp;
	char fname[50];

	printf ("Введите имя файла: ");
	scanf  ("%s", fname);
	fp = fopen (fname, "r");
	if (fp == NULL)
	{
		printf ("Не удается открыть файл. Программа завершена.\n");
		exit (1);
	}
	/* getc (fp) получает символ из открытого файла */
	while ((ch = getc (fp)) != EOF)
		putchar (ch);

	fclose (fp);

	return 0;
}

/*
$ ./file_eof 
Введите имя файла: mywords
Test text that I type myself one by one character in terminal
*/