/* cypher1.c -- вносит изменения во входные данные, сохраняя пробелы */
#include <stdio.h>
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar ();
	while (ch != '\n') {		/* while ((ch = getchar()) != '\n') */
		if (ch == SPACE)
			putchar (ch);
		else
			putchar (ch + 1);

		ch = getchar ();		/* тогда не нужен */
	}
	putchar (ch);

	return 0;
}

/*
19:28 $ ./cypher1 
ABCD EFGH ab cd ef gh
BCDE FGHI bc de fg hi

$ ./cypher1 
Use the source, Luke!
Vtf uif tpvsdf- Mvlf"
*/