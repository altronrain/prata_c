/* dyn_arr.c  -- динамически выделяемый массив */
#include <stdio.h>
#include <stdlib.h>	/* malloc(), free() */

int main (void)
{
	double *ptd;
	int max = 0;
	int number;
	int i = 0;

	puts ("Введте максвальное количество элементов типа double.");

	if (scanf ("%d", &max) != 1) {
		puts ("Количество введено некорректно -- программа завершена.");
		exit (EXIT_FAILURE);
	}

	ptd = (double *) malloc (max * sizeof (double));

	if (ptd == NULL) {
		puts ("Не удалось выделить память -- программа завершена.");
		exit (EXIT_FAILURE);
	}

	/* ptd указывает на первый элемент массива из max элементов */
	puts ("Введите значеня (q для выхода):");

	while (i < max && scanf ("%lf", &ptd[i]) == 1)
		++i;

	printf ("Введено %d элементов:\n", number = i);

	for (i = 0; i < number; i++) {
		printf ("%7.2f ", ptd[i]);
		if (i % 7 == 6)
			putchar ('\n');
	}

	if (i % 7 != 0)
		putchar ('\n');

	puts ("Программа завершена.");

	free (ptd);

	return 0;
}
/*
$ ./dyn_arr 
Введте максвальное количество элементов типа double.
10
Введите значеня (q для выхода):
23.00
55.34
12.95
67.83
18.77
42.01
56.90
15.61
77.38
65.44
Введено 10 элементов:
  23.00   55.34   12.95   67.83   18.77   42.01   56.90 
  15.61   77.38   65.44 
Программа завершена.
*/