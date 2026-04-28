/* copy1.c  -- использование функции strcpy() */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5

char * s_gets (char * st, int n);

int main (void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;

	printf ("Input %d words, starting wityh 'c' letter:\n", LIM);

	while (i < LIM && s_gets (temp, SIZE)) {
		if (temp[0] != 'c')
			printf ("%s do not starts with 'c'!\n", temp);
		else {
			strcpy (qwords[i], temp);
			i++;
		}
	}

	puts ("The list of accepted words:");

	for (i = 0; i < LIM; i++)
		puts (qwords[i]);

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
$ ./copy1 
Input 5 words, starting wityh 'c' letter:
can
clown
crown
crab
dog
dog do not starts with 'c'!
cloud
The list of accepted words:
can
clown
crown
crab
cloud
*/