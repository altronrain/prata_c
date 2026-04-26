/* compback.c  -- возвращаемые значения функции strcmp() */
#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"

int main (void)
{
	printf ("strcmp (\"A\", \"A\") возвращает ");
	printf ("%d\n", strcmp ("A", "A"));

	printf ("strcmp (\"A\", \"B\") возвращает ");
	printf ("%d\n", strcmp ("A", "B"));

	printf ("strcmp (\"B\", \"A\") возвращает ");
	printf ("%d\n", strcmp ("B", "A"));

	printf ("strcmp (\"C\", \"A\") возвращает ");
	printf ("%d\n", strcmp ("C", "A"));

	printf ("strcmp (\"Z\", \"a\") возвращает ");
	printf ("%d\n", strcmp ("Z", "a"));

	printf ("strcmp (\"apples\", \"apple\") возвращает ");
	printf ("%d\n", strcmp ("apples", "apple"));

	return 0;
}
/*
$ ./compback 
strcmp ("A", "A") возвращает 0
strcmp ("A", "B") возвращает -1
strcmp ("B", "A") возвращает 1
strcmp ("C", "A") возвращает 1
strcmp ("Z", "a") возвращает -1
strcmp ("apples", "apple") возвращает 1
*/