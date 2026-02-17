/* 5charreplace.c -- замена символов в выводе

Выполните упражнение 4, но с применением оператора switch.
*/
#include <stdio.h>

int main(void)
{
	char ch;
	int rc = 0;

	while ((ch = getchar()) != '#')
	{
		switch (ch) {
			case '.' :
				printf ("!");
				rc++;
				break;
			case '!' :
				printf ("!!");
				rc++;
				break;
			default :
				printf ("%c", ch);
		}
	}

	printf ("\n");
	printf ("Было проведено %d замен(-ы)\n", rc);

	return 0;
}

/*
$ ./5charreplace 
Lorem. Ipsum. Mane! Amen!!#
Lorem! Ipsum! Mane!! Amen!!!!
Было проведено 5 замен(-ы)
*/