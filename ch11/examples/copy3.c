/* copy3.c  -- использование функции strncpy() */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGSIZE 7
#define LIM 5

char * s_gets (char * st, int n);

int main (void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;

	printf ("Input %d words, starting wityh 'q' letter:\n", LIM);

	while (i < LIM && s_gets (temp, SIZE)) {
		if (temp[0] != 'q')
			printf ("%s do not starts with 'q'!\n", temp);
		else {
			strncpy (qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
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
$ ./copy3 
Input 5 words, starting wityh 'q' letter:
quazar
quality
quartz
quote
bill
bill do not starts with 'q'!
quiet
The list of accepted words:
quazar
qualit
quartz
quote
quiet
*/