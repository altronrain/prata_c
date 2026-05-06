/* q2.c  -- что выведет программа */
#include <stdio.h>

int main (void)
{
	char note[] = "See you tomorrow in the cafe.";
	char *ptr;

	ptr = note;
	puts (ptr);	/* "See you tomorrow in the cafe." */
	puts (++ptr);	/* "ee you tomorrow in the cafe." */
	note[7] = '\0';
	puts (note);	/* "See you" */
	puts (++ptr);	/* "e you" */

	return 0;
}
/*
$ ./q2
See you tomorrow in the cafe.
ee you tomorrow in the cafe.
See you
e you
*/