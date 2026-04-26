/* put1.c  -- использование собственной функции put1()

Поведение put1: выводит строку без добавления символа \n
*/
#include <stdio.h>

void put1 (const char *);

int main (void)
{
	char words[] = "I am a test string";

	put1 (words);
	printf ("\n");

	return 0;
}

void put1 (const char * string)
{
	while (*string != '\0')		/* while (*string) -- более C-way форма записи. \0 == False */
		putchar (*string++);	/* приоритет ++ выше чем *, инкрементируем указатель */
}
/*
$ ./put1
I am a test string
*/