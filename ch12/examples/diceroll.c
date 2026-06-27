/* diceroll.c  -- эмуляция игры в кости

Компилировать вместе с manydice.c
*/
#include <stdio.h>
#include <stdlib.h>		/* rand() */
#include "diceroll.h"		/* наш заголовочный файл, искать локально */

int roll_count = 0;		/* статическая переменная с внешним связыванием */
/*
Фактически тут еще extern int roll_count; из заголовочного файла
Ссылочное объявление. Допустимо сколько угодно
*/

static int rollem (int sides)	/* доступна только в данном файле */
{
	int roll;

	roll = rand () % sides + 1;
	++roll_count;		/* подсчет вызовов */

	return roll;
}

int roll_n_dice (int dice, int sides)
{
	int d;
	int total = 0;

	if (sides < 2) {
		printf ("Требуются, по меньшей мере, 2 грани.\n");

		return -2;
	}
	if (dice < 1) {
		printf ("Требуется, по меньшей мере, 1 кость.\n");

		return -1;
	}

	for (d = 0; d < dice; d++)
		total += rollem (sides);

	return total;
}
