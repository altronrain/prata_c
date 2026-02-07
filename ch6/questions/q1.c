/* q1.c -- значение переменной quack
Каким будет значение quack после выполнения каждой строки кода?
Каждый из последних пяти операторов использует значение quack,
сгенерированное предшествующим оператором.
*/
#include <stdio.h>

int main(void)
{
	int quack = 2;

	quack += 5;				/* quack = 7 */
	printf("quack = %d\n", quack);
	quack *= 10;				/* quack = 70 */
	printf("quack = %d\n", quack);
	quack -= 6;				/* quack = 64 */
	printf("quack = %d\n", quack);
	quack /= 8;				/* quack = 8 */
	printf("quack = %d\n", quack);
	quack %= 3;				/* quack = 2 */
	printf("quack = %d\n", quack);

	return 0;
}

/*
$ ./q1
quack = 7
quack = 70
quack = 64
quack = 8
quack = 2
*/