/* str_cat.c  -- объединение двух строк с помощью функции strcat() */
#include <stdio.h>
#include <string.h>
#define SIZE 80

char * s_gets (char * st, int n);

int main (void)
{
	char flower[SIZE];
	char addon[] = " smells like old felt boots.";

	puts ("What's your favorite flower?");

	if (s_gets (flower, SIZE)) {
		strcat (flower, addon);
		puts (flower);
		puts (addon);
	}
	else
		puts ("EOF encountered!");

	puts ("Program is finished.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets (st, n, stdin);

	if (ret_val != NULL) {	/* или просто ret_val, но не рекомендуется */
		while (st[i] != '\n' && st[i] != '\0')
			i++;

		if (st[i] == '\n')
			st[i] = '\0';
		else	/* requires words[i] == '\0' */
			while (getchar () != '\n')
				;
	}

	return ret_val;
}
/*
$ ./str_cat 
What's your favorite flower?
Dandelion
Dandelion smells like old felt boots.
 smells like old felt boots.
Program is finished.
*/