/* join_chck.c  -- объединение строк с предварительной проверкой размера */
#include <stdio.h>
#include <string.h>
#define SIZE 35
#define BUGSIZE 13

char * s_gets (char * st, int n);

int main (void)
{
	char flower[SIZE];
	char addon[] = " smells like old felt boots.";
	char bug[BUGSIZE];
	int available;

	puts ("What's your favorite flower?");
	s_gets (flower, SIZE);

	if ((strlen (addon) + strlen (flower) +1) <= SIZE)
		strcat (flower, addon);

	puts (flower);
	puts ("What's your favorite bug?");
	s_gets (bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat (bug, addon, available);
	puts (bug);

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
$ ./join_chk 
What's your favorite flower?
Dandelion
Dandelion
What's your favorite bug?
Ladybug
Ladybug smel
Program is finished.

$ ./join_chk 
What's your favorite flower?
Rose
Rose smells like old felt boots.
What's your favorite bug?
Ladybug
Ladybug smel
Program is finished.
*/