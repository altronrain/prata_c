/* q2.c -- напишите заголовки ANSI C для указанных функций

- donut() принимает аргумент int и выводит количество нулей,
соответствующее значению этого аргумента;
- gear() принимает два аргумента int и возвращает значение типа int;
- guess() не принимает аргументов и возвращает значение типа int;
- stuff_it() принимает значение double и адрес переменной double и запоминает первое
значение в заданной ячейке;

*/
#include <stdio.h>

void donut (int num);
int gear (int a, int b);
int guess (void);
void stuff_it (double num, double *addr);

int main (void)
{
	int num = 5;
	int a = 10, b = 40;
	double num2;

	printf ("Я напечатаю %d нулей: ", num);
	donut (num);
	printf ("Я выведу большее из %d и %d: %d\n", a, b, gear (a, b));
	printf ("Ответ на вопрос вселенной и всё такое: %d\n", guess());
	printf ("Я помещу значение %lf по адресу %p\n", 5.00, &num2);
	stuff_it (5.00, &num2);
	printf ("Вот что лежит по адресу %p: %lf\n", &num2, num2);

	return 0;
}

void donut (int num)
{
	if (num < 0) {
		printf ("Число должно быть положительным");
		return;
	}

	while (num > 0) {
		putchar ('0');
		num--;
	}

	putchar ('\n');
}

int gear (int a, int b) {
	return a > b ? a : b;
}

int guess (void)
{
	return 42;
}

void stuff_it (double num, double * addr)
{
	*addr = num;			/* разыменование, запись в ячейку с заданным адресом переданного значения */
}

/*
$ ./q2 
Я напечатаю 5 нулей: 00000
Я выведу большее из 10 и 40: 40
Ответ на вопрос вселенной и всё такое: 42
Я помещу значение 5.000000 по адресу 0x7ffccf0c4208
Вот что лежит по адресу 0x7ffccf0c4208: 5.000000
*/