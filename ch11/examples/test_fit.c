/* test_fit.c  -- использование функции укорачивания строк

Для подсчета длины строки применяется библиотечная функция strlen()
*/
#include <stdio.h>
#include <string.h>	/* прототипы строковых функций */

void fit (char *, unsigned);

int main (void)
{
	char mesg[] = "Everything should be as simple as possible,"
		      " but no more.";

	puts (mesg);
	fit (mesg, 35);
	puts (mesg);
	puts ("Let's look at a few more lines.");
	puts (mesg + 36);

	return 0;
}

void fit (char * string, unsigned size)
{
	if (strlen (string) > size)
		string[size] = '\0';
}
/*
$ ./test_fit 
Everything should be as simple as possible, but no more.
Everything should be as simple as p
Let's look at a few more lines.
ssible, but no more.
*/