/* sizeof.c  -- использование операции sizeof */
/* 
В примере применяется определенный в стандарте C99 модификатор %zd;
Если в системе модификатор %zd не поддерживается, стоит попробовать %lu или %u
*/
#include <stdio.h>

int main(void)
{
	int n = 0;
	size_t intsize;

	intsize = sizeof (int);
	printf("n = %d, состоит из %zd байтов; все значения int имеют %zd байтов.\n",
		n, sizeof n, intsize);

	return 0;
}

/*
$ ./sizeof 
n = 0, состоит из 4 байтов; все значения int имеют 4 байтов.
*/