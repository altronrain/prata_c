/* colddays.c -- вычисляет процет случаев, когда температура опускается ниже нуля */
#include <stdio.h>

int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;

	printf ("Введите список минимальных дневных температур.\n");
	printf ("Используйте шкалу Цельсия; для завершения введите q.\n");

	while (scanf ("%f", &temperature) == 1) {
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}

	if (all_days != 0)
		printf ("%d - общее количество дней: %.1f%% с температурой ниже нуля.\n",
				all_days, 100.0 * (float) cold_days / all_days);

	if (all_days == 0)
		printf ("Данные не введены!\n");

	return 0;
}

/*
$ ./colddays 
Введите список минимальных дневных температур.
Используйте шкалу Цельсия; для завершения введите q.
10 7 4 1 0 0 -2 -4 -2.5 -6 -12 -5 0 4 6 2 -1.5 q
17 - общее количество дней: 41.2% с температурой ниже нуля.
*/