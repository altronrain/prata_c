/* electric.c -- подсчитывает сумму для счета за электроэнергию */
#include <stdio.h>
#define RATE1 0.13230										/* тарифная сетка */
#define RATE2 0.15040
#define RATE3 0.30025
#define RATE4 0.34025
#define BREAK1 360.0										/* контрольные точки смены тарифов */
#define BREAK2 468.0
#define BREAK3 720.0
#define BASE1 (RATE1 * BREAK1)								/* стоимость 360 кВт/ч */
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))			/* стоимость 468 кВт/ч */
#define BASE3 (BASE1 + BASE2 + (RATE3 * (BREAK3 - BREAK2)))	/* стоимость 720 кВт/ч */

/* NB: Препроцессор не вычисляет константы BASE*
   Компилятор вычислит выражение и подставит его вместо имени константы */

int main(void)
{
	double kwh, bill;

	printf ("Введите объем израсходованной электроэнергии в кВт/ч.\n");
	scanf ("%lf", &kwh);
	if (kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2)
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3)
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else
		bill = BASE3 + (RATE4 * (kwh - BREAK3));

	printf ("Сумма к оплате за %.1f кВт/ч составляет $%1.2f.\n", kwh, bill);

	return 0;
}

/*
$ ./electric 
Введите объем израсходованной электроэнергии в кВт/ч.
658.7
Сумма к оплате за 658.7 кВт/ч составляет $121.13.
*/