/* loc_stat.c  -- локальные статические переменнные */
#include <stdio.h>

void trystat (void);

int main (void)
{
	for (int count = 1; count <= 3; count++)
	{
		printf ("Начинается итерация %d:\n", count);
		trystat ();
	}

	return 0;
}

void trystat (void)
{
	int fade = 1;
	static int stay = 1;

	printf ("fade = %d\tstay = %d\n", fade++, stay++);
}
/*
$ ./loc_stat 
Начинается итерация 1:
fade = 1        stay = 1
Начинается итерация 2:
fade = 1        stay = 2
Начинается итерация 3:
fade = 1        stay = 3
*/