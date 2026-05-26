/* 14pow_cli.c -- возведение в степень с передачей аргументов через CLI

Напишите программу реализации степенной зависимости, которая работает на
основе командной строки:
- Первый аргумент -- число типа double, возводимое с степень.
- Второй аргумент -- целочисленный показатель степени.
*/
#include <stdio.h>
#include <stdlib.h>

double power (double n, int p);

int main(int argc, char **argv)
{
	double num;
	int pow;

	if (argc < 2 || (num = atof (argv[1])) < 1 || (pow = atoi (argv[2])) < 1) {
		printf ("Использование: %s (double)NUM (int)POW\n", argv[0]);

		return 1;
	}

	printf ("%.3g в степени %d равно %.5g\n", num, pow, power (num, pow));

	puts ("Программа завершена.");

	return 0;
}

double power (double n, int p)
{
	double pow = 1;
	int i;

	for (i = 1; i <= p; i++)
		pow *= n;

	return pow;
}
/*
$ ./14pow_cli
Использование: ./14pow_cli (double)NUM (int)POW

$ ./14pow_cli baba yaga
Использование: ./14pow_cli (double)NUM (int)POW

$ ./14pow_cli 3.14 null
Использование: ./14pow_cli (double)NUM (int)POW

$ ./14pow_cli 3.14 3
3.14 в степени 3 равно 30.959
Программа завершена.
*/