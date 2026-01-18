/* addemup.c  -- виды операторов */
#include <stdio.h>

int main(void)
{
	int count, sum;				/* оператор объявления */

	count = 0;					/* оператор присваивания */
	sum = 0;					/* оператор присваивания */

	while (count++ < 20) {		/* оператор цикла while */
		sum = sum + count;
		;						/* пустой оператор */
	}

	printf("sum = %d\n", sum);	/* оператор вызова функции */

	return 0;					/* оператор возврата */
}

/*
$ ./addemup 
sum = 210
*/