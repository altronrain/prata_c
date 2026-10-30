/* q5.c  -- выборочный вывод строк из файла

Напишите программу, которая принимает два аргумента командной строки.
Первым аргументом является символ, а вторым -- имя файла. Программа
должна выводить из файла только те строки, которые содержат указанный
символ.

Строки файла идентифицируются символом новой строки '\n'. Предположим, что ни
одна из строк по длине не превышает 256 символов. Возможно потребуется
использовать функцию fgets().
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 256

int main (int argc, char **argv)
{
	FILE *fp;
	char ch;
	char buf[LIMIT];

	if (argc != 3) {
		puts ("Введено некорректное количество аргументов");
		printf ("Usage: %s CHAR FILE\n", argv[0]);
		exit (1);
	}

	if (strlen (argv[1]) > 1) {
		puts ("Требовалось ввести символ а не строку");
		printf ("Usage: %s CHAR FILE\n", argv[0]);
		exit (1);
	}

	ch = argv[1][0];

	if ((fp = fopen (argv[2], "r")) == NULL) {
		puts ("Не удалось открыть указанный файл");
		exit (1);
	}

	while (fgets (buf, 256, fp) != NULL)
		if (strchr (buf, ch) != NULL)
			fputs (buf, stdout);

	fclose (fp);

	return 0;
}
/*
22:14 $ ./q5 i q5.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 256
int main (int argc, char **argv)
        if (argc != 3) {
                printf ("Usage: %s CHAR FILE\n", argv[0]);
                exit (1);
        if (strlen (argv[1]) > 1) {
                printf ("Usage: %s CHAR FILE\n", argv[0]);
                exit (1);
        if ((fp = fopen (argv[2], "r")) == NULL) {
                exit (1);
        while (fgets (buf, 256, fp) != NULL)
                if (strchr (buf, ch) != NULL)
*/