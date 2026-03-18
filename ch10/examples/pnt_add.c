/* pnt_add.c -- сложение указателей */
#include <stdio.h>
#define SIZE 4

int main (void)
{
	short dates[SIZE];
	short * pti;
	short index;
	double bills[SIZE];
	double * ptf;

	pti = dates;	/* присвоение указателю адреса массива (его первого элемента) */
	ptf = bills;

	printf ("%23s %15s\n", "short", "double");

	for (index = 0; index <= SIZE; index++)
		printf ("Указатели + %d: %10p %10p\n",
			index, pti + index, ptf + index);	/* демонстрация смещения в единицах хранения */

	return 0;
}

/*
$ ./pnt_add 
                  short          double
Указатели + 0: 0x7ffdc60bb590 0x7ffdc60bb570
Указатели + 1: 0x7ffdc60bb592 0x7ffdc60bb578
Указатели + 2: 0x7ffdc60bb594 0x7ffdc60bb580
Указатели + 3: 0x7ffdc60bb596 0x7ffdc60bb588
Указатели + 4: 0x7ffdc60bb598 0x7ffdc60bb590
*/