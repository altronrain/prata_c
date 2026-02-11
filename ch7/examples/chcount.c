/* chcount.c -- использование логической операции И при подсчете символов */
#include <stdio.h>
#define PERIOD '.'

int main(void)
{
	char ch;
	int charcount = 0;

	while ((ch = getchar()) != PERIOD) {
		if (ch != '"' && ch != '\'')
			charcount++;
	}

	printf ("Здесь имеется %d символов, отличных от кавычек.\n", charcount);

	return 0;
}

/*
$ ./chcount 
I said: "Jonny, don't start the fight!".
Здесь имеется 36 символов, отличных от кавычек.
*/