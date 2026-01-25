/* q1.c -- Все переменные имеют тип int. Найдите значение каждой из них */
#include <stdio.h>

int main(void)
{
	int x, y;

	x = (2 + 3) * 6;		/* x = 30 */
	printf("x = %d\n", x);
	x = (12 + 6) / 2 * 3;	/* x = 9 */
	printf("x = %d\n", x);
	y = x = (2 + 3) / 4;	/* y = 1; x = 1 */
	printf("y = %d; x = %d\n", y, x);
	y = 3 + 2 * (x = 7 / 2);	/* y = 9; x = 3 */
	printf("y = %d; x = %d\n", y, x);

	return 0;
}

/*
$ ./q1
x = 30
x = 27
y = 1; x = 1
y = 9; x = 3
*/