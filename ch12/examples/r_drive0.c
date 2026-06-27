/* r_drive0.c  -- тестирование функции rand0()

Компилировать вместе с rand0.c
*/
#include <stdio.h>

extern int rand0 (void);

int main (void)
{
	for (int count = 0; count < 5; count++)
		printf ("%d\n", rand0());

	return 0;
}

/*
$ ./r_drive0 
16838
5758
10113
17515
31051
$ ./r_drive0 
16838
5758
10113
17515
31051
*/

