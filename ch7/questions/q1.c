/* q1.c -- истинно ли выражение

Определите, какие выражения равны true, а какие -- false
 */
#include <stdio.h>

int main(void)
{

	if (100 > 3 && 'a' > 'c')	/* False */
		printf ("1: True\n");
	else
		printf ("1: False\n");

	if (100 > 3 || 'a' > 'c')	/* True */
		printf ("2: True\n");
	else
		printf ("2: False\n");

	if (!(100 > 3))				/* False */
		printf ("3: True\n");
	else
		printf ("3: False\n");

	return 0;
}

/*
$ ./q1
1: False
2: True
3: False
*/