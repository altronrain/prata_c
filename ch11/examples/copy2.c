/* copy2.c  -- использование функции strcpy() */
#include <stdio.h>
#include <string.h>
#define WORDS "worst"
#define SIZE 40

int main (void)
{
	const char * orig = WORDS;
	char copy[SIZE] = "Be the best you can be.";
	char * ps;

	puts (orig);
	puts (copy);
	ps = strcpy (copy + 7, orig);
	puts (copy);
	puts (ps);

	return 0;
}
/*
$ ./copy2 
worst
Be the best you can be.
Be the worst
worst
*/