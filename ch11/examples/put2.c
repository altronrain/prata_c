/* put2.c  -- использование собственной функции put2()

Поведение put2: выводит строку и подсчитывает символы
*/
#include <stdio.h>

int put2 (const char *);

int main (void)
{
	char words[] = "I am a test string";
	int num;

	num = put2 (words);
	printf ("В строке было %d символов.\n", num);

	return 0;
}

int put2 (const char * string)
{
	int count = 0;

	while (*string) {		/* \0 == False -- выход из цикла */
		putchar (*string++);	/* приоритет ++ выше чем *, инкрементируем указатель */
		count++;
	}
	putchar ('\n');			/* символ новой строки не учитываем */

	return (count);
}
/*
$ ./put2 
I am a test string
В строке было 18 символов.
*/