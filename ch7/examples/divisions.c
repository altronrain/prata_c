/* divisions.c -- вложенные операторы if для отображения делителей числа */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned long num;
	unsigned long div;
	bool isPrime;		/* флаг простого числа */

	printf ("Введите целое число для анализа;\n");
	printf ("для завершения введите q.\n");

	while (scanf ("%lu", &num) == 1) {
		for (div = 2, isPrime=true; (div * div) <= num; div++) {	/* нет смысла перебирать делители выше квадратного корня числа */
			if (num % div == 0) {
				if ((div * div) != num)
					printf ("%lu делится на %lu и %lu.\n", num, div, num / div);
				else
					printf ("%lu делится на %lu.\n", num, div);

				isPrime = false;
			}
		}

		if (isPrime)
			printf ("%lu является простым числом.\n", num);
		printf ("Введите следующее число для анализа;\n");
		printf ("для завершения введите q.\n");
	}

	printf ("Работа программы завершена.\n");

	return 0;
}

/*
$ ./divisions 
Введите целое число для анализа;
для завершения введите q.
16
16 делится на 2 и 8.
16 делится на 4.
Введите следующее число для анализа;
для завершения введите q.
5
5 является простым числом.
Введите следующее число для анализа;
для завершения введите q.
q
Работа программы завершена.
*/