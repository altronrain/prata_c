/* strptr.c  -- строки как указатели */
#include <stdio.h>

int main (void)
{
	printf ("%s, %p, %c\n", "We", "are", *"space rangers!");

	return 0;
}
/*
$ ./strptr 
We, 0x55bdbd6b0004, s
*/