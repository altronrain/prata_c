/* shoes1.c  -- преобразует размер обуви в дюймы */
#include <stdio.h>
#define ADJUST 7.31			/* символическая константа */

int main(void)
{
	const double SCALE = 0.333; /* переменная, которую не собираемся изменять */
	double shoe, foot;

	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Размер обуви (мужской) длина ступни\n");
	printf("%11.1f %16.2f дюймов\n", shoe, foot);

	return 0;
}

/*
$ ./shoes1 
Размер обуви (мужской) длина ступни
        9.0            10.31 дюймов
*/