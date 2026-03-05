/* loccheck.c  -- проверка для выяснения, где хранятся переменные */
#include <stdio.h>

void mikado (int);

int main (void)
{
	int pooh = 2, bah = 5;		/* локальные для main() */

	printf ("Внутри main() pooh = %d\t\t&pooh = %p\n", pooh, &pooh);
	printf ("Внутри main() bah  = %d\t\t&bah  = %p\n", bah, &bah);
	mikado (pooh);

	return 0;
}

void mikado (int bah)			/* переменная bah будет иметь фактическое значение pooh */
{
	int pooh = 10;

	printf ("Внутри mikado() pooh = %d\t&pooh = %p\n", pooh, &pooh);
	printf ("Внутри mikado() bah  = %d\t&bah  = %p\n", bah, &bah);
}

/*
$ ./loccheck 
Внутри main() pooh = 2          &pooh = 0x7ffe3dedb78c
Внутри main() bah  = 5          &bah  = 0x7ffe3dedb788
Внутри mikado() pooh = 10       &pooh = 0x7ffe3dedb76c
Внутри mikado() bah  = 2        &bah  = 0x7ffe3dedb75c
*/