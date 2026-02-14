/* q1.c -- программа с ошибками

В приведенной ниже программе присутствуют излишне сложные выражения
отношений, а также откровенные ошибки. Упростите программу и исправьте
ошибки.

#include <stdio.h>
int main(void)
{
	int weight, height;

		scanf ("%d, weight, height);
		if (weight < 100 && height > 64)
			if (height >= 72)
				printf("Ваш вес слишком мал для вашего роста.\n");
		else if (height < 72 && > 64)
			printf("Ваш вес мал для вашего роста.\n");
	else if (weight > 300 && !(weight <= 300)
				&& height < 48)
		if (!(height >= 48))
			printf("Ваш рост мал для вашего веса.\n");
	else
		printf("У вас идеальный вес.\n");

	return 0;
}
*/
#include <stdio.h>

int main(void)
{
	int weight, height;

	scanf ("%d%d", &weight, &height);
	if (weight < 100 && height > 64)
		if (height >= 72)
			printf("Ваш вес слишком мал для вашего роста.\n");
		else
			printf("Ваш вес мал для вашего роста.\n");
	else if (weight > 300 && height < 48)
		printf("Ваш рост мал для вашего веса.\n");
	else
		printf("У вас идеальный вес.\n");

	return 0;
}

/*
$ ./q3
95 77
Ваш вес слишком мал для вашего роста.

$ ./q3
95 65
Ваш вес мал для вашего роста.

$ ./q3
301 47
Ваш рост мал для вашего веса.

$ ./q3
200 55
У вас идеальный вес.
*/