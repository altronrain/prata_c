/* str_len.c  -- подсчет длины строки с использованием функции strlen() */
#include <stdio.h>
#include <string.h>	/* прототипы строковых функций */

int main (void)
{
	char mesg[] = "test";

	printf ("Length of the \"test\" string is: %zu\n", strlen (mesg));

	return 0;
}
/*
$ ./str_len 
Length of the "test" string is: 4
*/