/* showchar1.c -- программа с крупной проблемой ввода-вывода */
#include <stdio.h>

void display (char cr, int lines, int width);

int main(void)
{
	int ch;
	int rows, cols;

	printf ("Введите символ и два целых числа:\n");

	while ((ch = getchar ()) != '\n')
	{
		scanf ("%d%d", &rows, &cols);	/* оставляет '\n' в очереди ввода */
		display (ch, rows, cols);		/* может быть предупреждение. Усечение до char */

		printf ("Введите еще один символ и два целых числа:\n");
		printf ("Для завершения введите символ новой строки.\n");
	}

	printf ("Программа завершена.\n");

	return 0;
}

void display (char cr, int lines, int width)
{
	int row, col;

	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar (cr);
		putchar ('\n');
	}
}
/*
21:08 $ ./showchar1 
Введите символ и два целых числа:
a 10 10
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaaaaaaaaa
Введите еще один символ и два целых числа:
Для завершения введите символ новой строки.
Программа завершена.
*/