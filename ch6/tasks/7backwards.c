/* 7backwards.c  -- вывод слова задом наперед

Напишите программу, которая читает слово в символьный массив, а затем выводит
это слово в обратном порядке. Подсказка: воспользуйтесь функцией strlen() для
вычисления индекса последнего символа массива.

*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[100];
	int i;

	printf ("Введите слово: ");
	scanf ("%s", word);

	for (i = strlen(word); i >= 0; i--) {
		printf ("%c", word[i]);
	}

	printf ("\n");

	return 0;
}

/*
$ ./7backwards 
Введите слово: programming
gnimmargorp
*/