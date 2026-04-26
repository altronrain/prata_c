/* put_put.c  -- функции вывода, определенные пользователем */
#include <stdio.h>

void put1 (const char *);
int put2 (const char *);

int main (void)
{
	put1 ("If I had as much money,");
	put1 (" as I could spend,\n");
	printf ("Symbols count: %d\n",	/* put2() будет выполнен прежде (в процессе) */
		put2 ("I would never bother about mending old shoes."));

	return 0;
}

void put1 (const char * string)
{
	while (*string != '\0')		/* while (*string) -- более C-way форма записи. \0 == False */
		putchar (*string++);	/* приоритет ++ выше чем *, инкрементируем указатель */
}

int put2 (const char * string)
{
	int count = 0;

	while (*string) {		/* \0 == False -- выход из цикла */
		putchar (*string++);	/* приоритет ++ выше чем *, инкрементируем указатель */
		count++;
	}
	putchar ('\n');			/* символ новой строки не учитываем */

	return (count);
}
/*
$ ./put_put 
If I had as much money, as I could spend,
I would never bother about mending old shoes.
Symbols count: 45
*/