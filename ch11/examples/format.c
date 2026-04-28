/* copy1.c  -- использование функции sprintf() */
#include <stdio.h>
#define MAX 20

char * s_gets (char * st, int n);

int main (void)
{
	char first[MAX];
	char last[MAX];
	char formal[2 * MAX + 10];
	double prize;

	puts ("Enter your name:");
	s_gets (first, MAX);
	puts ("Enter your surname:");
	s_gets (last, MAX);
	puts ("Enter the prize sum:");
	scanf ("%lf", &prize);
	sprintf (formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts (formal);

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
$ ./format 
Enter your name:
Kirill
Enter your surname:
Komarov
Enter the prize sum:
500.33
Komarov, Kirill             : $500.33


*/