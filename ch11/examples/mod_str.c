/* mod_str.c  -- модификация строк */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void to_upper (char *);
int punct_count (const char *);

int main (void)
{
	char line[LIMIT];
	char * find;

	puts ("Please input the string:");
	fgets (line, LIMIT, stdin);
	find = strchr (line, '\n');

	if (find)
		*find = '\0';

	to_upper (line);
	puts (line);
	printf ("This string contains %d punct characters.\n",
		punct_count (line));

	return 0;
}

void to_upper (char * str)
{
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

int punct_count (const char * str)
{
	int ct = 0;

	while (*str) {
		if (ispunct (*str))
			ct++;
		str++;
	}

	return ct;
}
/*
$ ./mod_str 
Please input the string:
Platipus is unique creature, believe me!
PLATIPUS IS UNIQUE CREATURE, BELIEVE ME!
This string contains 2 punct characters.
*/