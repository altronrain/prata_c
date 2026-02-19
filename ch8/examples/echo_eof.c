/* echo.c -- повтор ввода до достижения конца файла */
#include <stdio.h>

int main(void)
{
	int ch;

	while ((ch = getchar ()) != EOF)
		putchar (ch);

	return 0;
}

/*
$ ./echo_eof 
pupupu
pupupu
tratata#
tratata#
dududu
dududu
*/