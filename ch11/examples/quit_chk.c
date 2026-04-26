/* quit_chk.c  -- использование функции strcmp() для остановки ввода */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"

char * s_gets (char *st, int n);

int main (void)
{
	char input[LIM][SIZE];
	int ct = 0;

	printf ("Input up to %d strings (or quit for exit):\n", LIM);

	while (ct < LIM && s_gets (input[ct], SIZE) != NULL &&
	       strcmp (input[ct], STOP) != 0)
		ct++;

/*
Модификация для выхода по пустой строке:
	while (ct < LIM && s_gets (input[ct], SIZE) != NULL &&
	       input[ct][0] != '\0')

s_gets() заменит \n на нулевой символ, так что по пустой строке выйдем.
*/

	printf ("%d string entered\n", ct);

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
$ ./quit_chk 
Input up to 10 strings (or quit for exit):
Something wrong
Or no
I don't know
Better exit now
quit
4 string entered
*/