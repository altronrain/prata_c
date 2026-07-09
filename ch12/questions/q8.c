/* q8.c  -- что выведет программа */
#include <stdio.h>

char color = 'B';

void first (void);
void second (void);

int main (void)
{
	extern char color;

	printf ("color in main() is %c\n", color);	/* B */
	first ();					/* R */
	printf ("color in main() is %c\n", color);	/* B */
	second ();					/* G */
	printf ("color in main() is %c\n", color);	/* B */

	return 0;
}

void first (void)
{
	char color;
	color = 'R';
	printf ("color in first() is %c\n", color);
}

void second (void)
{
	char color;
	color = 'G';
	printf ("color in second() is %c\n", color);
}
/*
$ ./q8 
color in main() is B
color in first() is R
color in main() is B
color in second() is G
color in main() is B
*/