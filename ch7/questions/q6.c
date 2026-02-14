/* q6.c -- вывод программы

Что выведет следующая программа?

#include <stdio.h>
int main(void)
{
	int i = 0;
	while (i < 3) {
		switch (i++) {
			case 0 : printf("fat ");
			case 1 : printf("hat ");
			case 2 : printf("cat ");
			default: printf("Oh no!");
		}
		putchar ('\n');
	}

	return 0;
}
*/
#include <stdio.h>

int main(void)
{
	int i = 0;
	while (i < 3) {						/* "fat hat cat Oh no!\nhat cat Oh no!\ncat Oh no!\n" */
		switch (i++) {					/* Инкремент после вычисления выражения */
			case 0 : printf("fat ");	/* нет break в метках */
			case 1 : printf("hat ");
			case 2 : printf("cat ");
			default: printf("Oh no!");
		}
		putchar ('\n');
	}

	return 0;
}

/*
$ ./q6 
fat hat cat Oh no!
hat cat Oh no!
cat Oh no!
*/