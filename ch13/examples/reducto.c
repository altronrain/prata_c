/* reducto.c -- сокращение файлов на две трети */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main (int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;

	/* проверка аргументов командной строки */
	if (argc < 2) {
		fprintf (stderr, "Usage: %s file_name\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	/* настройка ввода */
	if ((in = fopen (argv[1], "r")) == NULL) {
		fprintf (stderr, "Cannot open file \"%s\"\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	/* настройка вывода */
	strncpy (name, argv[1], LEN - 5);	/* копирование имени файла */
	name[LEN - 5] = '\0';			/* strncpy может и не скопировать '\0', перестраховка */
	strcat (name, ".red");			/* добавление .red */

	if ((out = fopen (name, "w")) == NULL) {
		fprintf (stderr, "Cannot create output file\n");
		exit (3);
	}

	/* копирование данных */
	while ((ch = getc (in)) != EOF)
		if (count++ %3 == 0)
			putc (ch, out);		/* запись каждого 3 символа */

	/* очистка */
	if (fclose (in) != 0 || fclose (out) != 0)
		fprintf (stderr, "Error occured while closing files\n");

	return 0;
}
/*
$ ./reducto Eddy

$ cat eddy
So even Eddy came oven ready.

$ cat eddy.red
Send money
*/