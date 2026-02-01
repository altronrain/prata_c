/* for_down.c -- организация обратного счетчика с применением цикла for */
#include <stdio.h>

int main(void)
{
	int secs;

	for (secs = 5; secs > 0; secs--)
		printf ("%d секунд(ы)!\n", secs);
	printf ("Ключ на зажигание!\n");

	return 0;
}

/*
$ ./for_down 
5 секунд(ы)!
4 секунд(ы)!
3 секунд(ы)!
2 секунд(ы)!
1 секунд(ы)!
Ключ на зажигание!
*/