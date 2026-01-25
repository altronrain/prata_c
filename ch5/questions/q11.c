/* q11.c -- Что выведет эта программа

#define MESG "COMPUTER BYTES DOG"
#include <stdio.h>

int main(void)
{
	int n = 0;

	while (n < 5)
		printf("%s", MESG);
		n++;
	printf("На этом все.\n");

	return 0;
}

Программа уйдет в бесконечный цикл вывода сообщения на экран
А исправленная программа напечатает:

"COMPUTER BYTES DOG" 5 раз без разделителей между фразами и в той же строке допишет "На этом все." и переведет строку
*/
#define MESG "COMPUTER BYTES DOG"
#include <stdio.h>

int main(void)
{
	int n = 0;

	while (n < 5) {
		printf("%s", MESG);
		n++;
	}
	printf("На этом все.\n");

	return 0;
}

/*
18:53 $ ./q11
COMPUTER BYTES DOGCOMPUTER BYTES DOGCOMPUTER BYTES DOGCOMPUTER BYTES DOGCOMPUTER BYTES DOGНа этом все.
*/