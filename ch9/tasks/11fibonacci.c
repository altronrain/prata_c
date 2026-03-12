/* 11fibonacci.c  -- вычисление чисел Фибоначчи

Напишите и протестируйте функцию Fibonacci(), в которой для вычисления чисел
Фибоначчи вместо рекурсии применяется цикл.
*/
#include <stdio.h>

void Fibonacci (unsigned);
unsigned get_unsigned (void);

int main (void)
{
	unsigned num;

	printf ("Введите длину последовательности Фибоначчи: ");
	num = get_unsigned ();

	Fibonacci (num);
	printf ("\n");

	return 0;
}

unsigned get_unsigned (void)
{
	int input;
	int res;
	char ch;				/* лучше использовать int, getchar может вернуть -1 */

	while (((res = scanf ("%d", &input)) == 1 && input < 0) || res != 1)
	{
		while (getchar () != '\n')
			;	/* "отбросить некорректный ввод" с выводом на терминал */
		printf ("Введенное число не является положительным.\nВведите "
			"положительное число, такое как 10 или 3: ");
	}
	return input;
}

void Fibonacci (unsigned n)
{
	int i;
	int n1 = 0, n2 = 1;
	int temp;

	for (i = 1; i <= n; i++) {
		printf ("%d ", n2);
		temp = n2;
		n2 = n1 + n2;
		n1 = temp;
	}
}

/*
$ ./11fibonacci 
Введите длину последовательности Фибоначчи: -5
Введенное число не является положительным.
Введите положительное число, такое как 10 или 3: 10
1 1 2 3 5 8 13 21 34 55
*/