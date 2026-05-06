/* q3.c  -- что выведет программа */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char food[] = "Delicious";
	char *ptr;

	ptr = food + strlen(food);

	while (--ptr >= food)	/* Separate rows for: s us ous ious ... Delicious */
		puts (ptr);

	return 0;
}
/*
$ ./q3 
s
us
ous
ious
cious
icious
licious
elicious
Delicious
*/