/* echo.c -- повтор ввода */
#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = getchar ()) != '#')
		putchar (ch);

	return 0;
}

/*
$ ./echo 
abcd
abcd
bububu
bububu
tratata#
tratata				<- no new line here
*/