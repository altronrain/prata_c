/* q3.c -- напишите заголовки ANSI C для указанных функций

- n_to_char() принимает аргумент int и возвращает значение типа char;
- digits() принимает аргументы double и int и возвращает значение типа int;
- which() принимает в качестве аргументов два адреса значений double
и возвращает адрес значения типа double;
- random() не принимает аргументов и возвращает значение типа int;

*/
#include <stdio.h>

char n_to_char (int num);
int digits (double, int);
double * which (double *, double *);
int random (void);

int main (void)
{
	int n = 38;
	double num = 11.1234567890;
	int dig = 6;
	double num1 = 5.00, num2 = 10.00;

	printf ("Числом %d предствален символ: %c\n", n, n_to_char (n));
	printf ("Я выведу сумму %d знакомест (чисел) дробной части числа %.11lf: %d\n",
		dig, num, digits (num, dig));
	printf ("Ответ на вопрос вселенной и всё такое: %d\n", random());
	printf ("Из адресов %p и %p число num1 содержится по адресу %p\n",
		&num1, &num2, which (&num1, &num2));

	return 0;
}

char n_to_char (int num)
{
	return (char) num;
}

int digits (double a, int b) {
	double fract;
	int acc = 0;

	fract = a - (int) a;

	while (b > 0) {
		fract = fract * 10;
		acc += (int) fract;
		fract = fract - (int) fract;
		b--;
	}

	return acc;
}

double * which (double * a, double * b)
{
	return *a == 5.00 ? a : b;			/* разыменование, обращение по адресу, проверка содержится ли там 5.00 */
}

int random (void)
{
	return 42;
}

/*
$ ./q3 
Числом 38 предствален символ: &
Я выведу сумму 6 знакомест (чисел) дробной части числа 11.12345678900: 21
Ответ на вопрос вселенной и всё такое: 42
Из адресов 0x7ffeacb69730 и 0x7ffeacb69728 число num1 содержится по адресу 0x7ffeacb69730
*/