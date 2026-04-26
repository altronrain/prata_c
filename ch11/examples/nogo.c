/* nogo.c  -- будет ли это работать? */
#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"
#define SIZE 40

char * s_gets (char * st, int n);

int main (void)
{
	char try[SIZE];

	puts ("Who's buried in Grant's tomb?");
	s_gets (try, SIZE);

	while (try != ANSWER) {		/* не сработает, так как сравниваем адреса строк а не сами строки */
		puts ("Wrong! Try again.");
		s_gets (try, SIZE);
	}
	puts ("Now it's the right answer!");

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
$ ./nogo 
Who's buried in Grant's tomb?
Old Bobby
Wrong! Try again.
Grant
Wrong! Try again.
Oh shi!
Wrong! Try again.
^C
*/