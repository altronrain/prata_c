/* cypher2.c -- вносит изменения во входные данные, оставляя неизменными
				символы, которые не являются буквами */
#include <stdio.h>
#include <ctype.h>
#define SPACE ' '

int main(void)
{
	char ch;

	while ((ch = getchar ()) != '\n') {
		if (isalpha(ch))
			putchar (ch + 1);
		else
			putchar (ch);
	}
	putchar (ch);

	return 0;
}

/*
$ ./cypher2
Look! It's a trap!
Mppl! Ju't b usbq!
*/