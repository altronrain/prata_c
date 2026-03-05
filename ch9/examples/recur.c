/* recur.c  -- иллюстрация рекурсии */
#include <stdio.h>

void up_and_down (int);

int main (void)
{
	up_and_down (1);

	return 0;
}

void up_and_down (int n)
{
	printf ("Уровень %d: ячейка n %p\n", n, &n); /* ascend */
	if (n < 4) up_and_down (n + 1);
	printf ("УРОВЕНЬ %d: ячейка n %p\n", n, &n); /* descend */
}

/*
$ ./recur 
Уровень 1: ячейка n 0x7ffe0b3b56bc
Уровень 2: ячейка n 0x7ffe0b3b569c
Уровень 3: ячейка n 0x7ffe0b3b567c
Уровень 4: ячейка n 0x7ffe0b3b565c
УРОВЕНЬ 4: ячейка n 0x7ffe0b3b565c
УРОВЕНЬ 3: ячейка n 0x7ffe0b3b567c
УРОВЕНЬ 2: ячейка n 0x7ffe0b3b569c
УРОВЕНЬ 1: ячейка n 0x7ffe0b3b56bc
*/