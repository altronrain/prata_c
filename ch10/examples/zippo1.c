/* zippo1.c  -- информация о многомерном массиве zippo */
#include <stdio.h>

int main (void)
{
	int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

	printf ("   zippo = %p,     zipo + 1 = %p\n", zippo, zippo + 1);	/* адресация внешнего массива */
	printf ("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);	/* адресация внутреннего массива */
	printf ("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);	/* равно значению выше */
	printf ("zippo[0][0] = %d\n", zippo[0][0]);				/* значение 1 элемента (вообще) */
	printf ("  *zippo[0] = %d\n", *zippo[0]);				/* равно значению выше */
	printf ("    **zippo = %d\n", **zippo);					/* равно значению выше */
	printf ("        zippo[2][1] = %d\n", zippo[2][1]);			/* значение 2 элемента 3 элемента внешнего массива */
	printf ("*(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));		/* равно значению выше */

	return 0;
}

/*
$ ./zippo1 
   zippo = 0x7ffdc0a6c730,     zipo + 1 = 0x7ffdc0a6c738
zippo[0] = 0x7ffdc0a6c730, zippo[0] + 1 = 0x7ffdc0a6c734
  *zippo = 0x7ffdc0a6c730,   *zippo + 1 = 0x7ffdc0a6c734
zippo[0][0] = 2
  *zippo[0] = 2
    **zippo = 2
        zippo[2][1] = 3
*(*(zippo + 2) + 1) = 3
*/