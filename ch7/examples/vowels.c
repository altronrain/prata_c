/* vowels.c -- использование множества меток */
#include <stdio.h>

int main(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct =u_ct = 0;

	printf ("Введите текст или # для завершения программы.\n");
	while ((ch = getchar()) != '#') {			/* или использовать toupper() */
		switch (ch) {
		case 'a' :
		case 'A' :
			a_ct++;
			break;
		case 'e' :
		case 'E' :
			e_ct++;
			break;
		case 'i' :
		case 'I' :
			i_ct++;
			break;
		case 'o' :
		case 'O' :
			a_ct++;
			break;
		case 'u' :
		case 'U' :
			u_ct++;
			break;				/* необязателен */
		default:
			break;
		}
	}

	printf ("Количество гласных:\tA\tE\tI\tO\tU\n");
	printf ("                   \t%d\t%d\t%d\t%d\t%d\n",
			a_ct, e_ct, i_ct, o_ct, u_ct);

	return 0;
}

/*
$ ./vowels 
Введите текст или # для завершения программы.
Luke, use your sword wisely. Amen!#
Количество гласных:     A       E       I       O       U
                        3       4       1       0       3
*/