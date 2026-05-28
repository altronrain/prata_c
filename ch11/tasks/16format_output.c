/* 16format_output.c -- форматированный вывод строк

Напишите программу, которая читает входные данные до тех пор, пока не встретится EOF,
и выводит их на экран. Программа должна распознавать и реализовывать следующие аргументы
командной строки:

	-p Вывод входных данных в том виде, как есть.
	-u Преобразование входных данных в верхний регистр.
	-l Преобразование водных данных в нижний регистр.

Кроме того, если аргумент входной строки не указан, программа должна вести себя так,
как если бы был задан аргумент -p.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 101

void to_upper (char *);
void to_lower (char *);
char * s_gets (char * st, int n);

int main (int argc, char **argv)
{
	char str[SIZE];

	puts ("Введите строку (или EOF для прекращения ввода):");

	if (s_gets (str, SIZE) == NULL) {
		puts ("Отсуствует ввод!");
		return 2;
	}

	printf ("\n");

	if (argc > 2) {
		printf ("Использование: %s [-pul]\n", argv[0]);
		return 1;
	}
	else if (argc == 2)
		if (strcmp (argv[1], "-p") == 0)
			printf ("Вывод данных в исходном виде: %s\n", str);
		else if (strcmp (argv[1], "-u") == 0) {
			to_upper (str);
			printf ("Вывод данных в верхнем регистре: %s\n", str);
		}
		else if (strcmp (argv[1], "-l") == 0) {
			to_lower (str);
			printf ("Вывод данных в нижнем регистре: %s\n", str);
		}
		else {
			printf ("Использование: %s [-pul]\n", argv[0]);
			return 1;
		}
	else
		printf ("Вывод данных в исходном виде: %s\n", str);

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

void to_upper (char * str)
{
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void to_lower (char * str)
{
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}
/*
$ ./16format_output 
Введите строку (или EOF для прекращения ввода):
Luke the Jedi -- sounds perfect!
Вывод данных в исходном виде: Luke the Jedi -- sounds perfect!

$ ./16format_output -u
Введите строку (или EOF для прекращения ввода):
Luke the Jedi -- sounds perfect!
Вывод данных в верхнем регистре: LUKE THE JEDI -- SOUNDS PERFECT!

$ ./16format_output -l
Введите строку (или EOF для прекращения ввода):
LUKE THE JEDI -- SOUNDS PERFECT!
Вывод данных в нижнем регистре: luke the jedi -- sounds perfect!

$ ./16format_output -ololo
Введите строку (или EOF для прекращения ввода):
LUKE THE JEDI -- SOUNDS PERFECT!

Использование: ./16format_output [-pul]

$ ./16format_output -p -l
Введите строку (или EOF для прекращения ввода):
LUKE THE JEDI -- SOUNDS PERFECT!

Использование: ./16format_output [-pul]

$ ./16format_output -u
Введите строку (или EOF для прекращения ввода):
Отсуствует ввод!
*/