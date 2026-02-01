/* for_13s.c -- счетчик с интервалом */
#include <stdio.h>

int main(void)
{
	int n;

	for (n = 2; n < 60; n = n + 13)
		printf ("%d\n", n);

	return 0;
}

/*
$ ./for_13s 
2
15
28
41
54
*/