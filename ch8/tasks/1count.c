/* 1count.c -- подсчет количества символов в входных данных 

Напишите программу, которая подсчитывает количество символов во входных
данных до достижения конца файла.
*/
#include <stdio.h>

int main(void)
{
	int ch;
	long cc = 0;

	while ((ch = getchar ()) != EOF)
		cc++;

	printf ("Прочитано %ld символов.\n", cc);

	return 0;
}

/*
$ ./1count <1count.c
Прочитано 346 символов.

$ cat test.txt 
This is a test string.
$ ./1count <test.txt 
Прочитано 23 символов.
*/