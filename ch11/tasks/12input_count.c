/* 12inputcount.c -- подсчет из строки ввода

Напишите программу, которая читает входные данные до тех пор, пока не встретится EOF,
и выводит:
- количество слов
- количество прописных букв
- количество строчных букв
- количество знаков препинания
- количество цифр

Используйте семейство функций ctype.h
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 101
#define MAX_LIMIT 1000000

char * s_gets (char *st, int n);
void symcount (const char *str);

int main (void)
{
	char str[SIZE];
	char full_input[MAX_LIMIT] = {0};

	puts ("Введите строку (или EOF для прекращения ввода):");

	while (fgets (str, SIZE, stdin) != NULL) {
		if (strlen (full_input) + strlen (str) + 1 >= MAX_LIMIT) {
			puts("Превышен лимит ввода.");
			break;
		}
		strcat(full_input, str);
	}

	symcount (full_input);

	puts ("\nГотово.\n");

	return 0;
}

void symcount (const char *str)
{
	const char *ptr = str;
	int w = 0, u = 0, l = 0, p = 0, n = 0;
	_Bool inword = 0;

	while (*ptr != '\0') {

		if (isupper (*ptr)) u++;
		if (islower (*ptr)) l++;
		if (ispunct (*ptr)) p++;
		if (isdigit (*ptr)) n++;
		if (!isspace (*ptr) && !inword) {
			inword = 1;	/* начало нового слова */
			w++;	/* считать слова */
		}
		if (isspace (*ptr) && inword)
			inword = 0;

		ptr++;

	}

	puts ("Во введенной фразе содержится:");
	printf ("%-3d слов\n", w);
	printf ("%-3d прописных букв\n", u);
	printf ("%-3d строчных букв\n", l);
	printf ("%-3d знаков препинания\n", p);
	printf ("%-3d цифр\n", n);
}
/*
$ printf "Luke, you are the greatest Jedi in the Star Wars Universe - Yoda tells.\n" | ./12input_count
Введите строку (или EOF для прекращения ввода):
Во введенной фразе содержится:
14  слов
6   прописных букв
49  строчных букв
3   знаков препинания
0   цифр

Готово.
*/