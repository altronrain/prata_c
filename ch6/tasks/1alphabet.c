/* 1alphabet.c  -- вывод алфавита

Напишите программу, которая создает массив из 26 элементов и помещает в него
26 строчных букв английского алфавита. Также предусмотрите вывод содержимого
этого массива.

*/
#include <stdio.h>

int main(void)
{
	char ch, alphabet[26];
	int i;

	for (i = 0, ch = 'a'; i < 26; i++, ch++) {
		printf ("%c ", alphabet[i] = ch);
	}

	printf ("\n");

	return 0;
}

/*
$ ./1alphabet 
a b c d e f g h i j k l m n o p q r s t u v w x y z
*/