/* starsrch.c  -- использование функции strncmp() */
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6

int main (void)
{
	const char * list[LISTSIZE] =
	{
		"astronomy", "astatism",
		"astrophysics", "ostracism",
		"asterism", "astrolabe"
	};
	int count = 0;

	for (int i = 0; i < LISTSIZE; i++)
		if (strncmp (list[i], "astro", 5) == 0) {
			printf ("Found: %s\n", list[i]);
			count++;
		}

	printf ("%d entries in the list starts with \"astro\"\n", count);

	return 0;
}
/*
$ ./starsrch 
Found: astronomy
Found: astrophysics
Found: astrolabe
3 entries in the list starts with "astro"
*/