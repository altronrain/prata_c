/* usehotel.c  -- определение стоимости номеров */
/* Компилируется совместно с hotel.c */
#include <stdio.h>
#include "hotel.h"	/* определение констант и функций */

int main (void)
{
	int nights;
	double hotel_rate;
	int code;

	while ((code = menu ()) != QUIT) {
		switch (code) {
			case 1 : hotel_rate = HOTEL1; break;
			case 2 : hotel_rate = HOTEL2; break;
			case 3 : hotel_rate = HOTEL3; break;
			case 4 : hotel_rate = HOTEL4; break;
			default : hotel_rate = 0.0;
				printf ("Ошибка!\n");
				break;
		}

		nights = getnights ();
		showprice (hotel_rate, nights);
	}

	printf ("Благодарим за использование и желаем успехов.\n");

	return 0;
}

/*
$ ./usehotel 

******************************************************************************
Введите число, соответствующее выбранному отелю:
1) Fairfield Arms             2) Hotel Olympic
3) Chertworthy Plaza          4) The Stockton
5) exit
******************************************************************************
3
На сколько суток вы бронируете номер? 1
Общая стоимость составляет $255.00.

******************************************************************************
Введите число, соответствующее выбранному отелю:
1) Fairfield Arms             2) Hotel Olympic
3) Chertworthy Plaza          4) The Stockton
5) exit
******************************************************************************
3
На сколько суток вы бронируете номер? 2
Общая стоимость составляет $497.25.

******************************************************************************
Введите число, соответствующее выбранному отелю:
1) Fairfield Arms             2) Hotel Olympic
3) Chertworthy Plaza          4) The Stockton
5) exit
******************************************************************************
q
Введитец целое число от 1 до 5.
5
Благодарим за использование и желаем успехов.
*/