/* q8.c  -- что выведет программа */
#include <stdio.h>

int main (void)
{
	char str1[] = "gawsie";
	char str2[] = "bletonism";
	char *ps;

	int i = 0;

	for (ps = str1; *ps != '\0'; ps++) {	/* why not *ps condition */
		if (*ps == 'a' || *ps == 'e')
			putchar (*ps);
		else
			(*ps)--;
		putchar (*ps);			/* non-conditional putchar() */
	}

	putchar ('\n');				/* favrhe\n  -- my mistake. faavrhee */

	while (str2[i] != '\0') {		/* why not str2[i] condition */
		printf ("%c", i % 3 ? str2[i] : '*');
		++i;
	}					/* *le*on*sm */
						/* better to add \n in the end */
	return 0;
}
/*
$ ./q8 
faavrhee
*le*on*sm
*/