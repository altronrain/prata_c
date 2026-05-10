/* q13.c  -- использование функции сравнения строк strcmp()

Перепишите программу из листинга 11.21, используя функции из ctype.h для
того, чтобы программа распознавала правильный ответ независимо от применения
пользователем прописных или строчных букв.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "Grant"
#define SIZE 40

char * s_gets (char * st, int n);
int str_cmp (char * st1, char * st2);

int main (void)
{
	char try[SIZE];

	puts ("Who's buried in Grant's tomb?");
	s_gets (try, SIZE);

	while (str_cmp (try, ANSWER) != 0) {
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

	if (ret_val) {
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

int str_cmp (char * st1, char * st2)
{
	char *ptr1 = st1;
	char *ptr2 = st2;
	
	while (*ptr1 || *ptr2) {

		if (toupper (*ptr1) < toupper (*ptr2))
			return -1;

		if (toupper (*ptr1) > toupper (*ptr2))
			return 1;

		ptr1++;
		ptr2++;
	}

	return 0;
}
/*
$ ./q13
Who's buried in Grant's tomb?
Billy
Wrong! Try again.
Jimmy
Wrong! Try again.
Grant Mnemonic 
Wrong! Try again.
gRaNt
Now it's the right answer!
*/