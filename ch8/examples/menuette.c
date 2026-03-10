/* menuette.c -- интерактивный ввод через меню */
#include <stdio.h>

void count (void);
char get_choice (void);
char get_first (void);
int  get_int (void);

int main(void)
{
	int choice;

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
			case 'a' : printf ("Покупайте дешево, продавайте дорого.\n"); break;
			case 'b' : putchar ('\a'); break; 	/* ASCII Bell (beep) */
			case 'c' : count (); break;
			default  : printf ("Ошибка!\n");
		}
	}

	printf ("Програма завершена.\n");

	return 0;
}

void count (void)
{
	int n, i;

	printf ("До какого предела вести подсчет? Введите целое число:\n");
	n = get_int ();
	for (i = 1; i <= n; i++)
		printf ("%d\n", i);

	while (getchar () != '\n')
		;
}

char get_choice (void)
{
	int ch;

	printf ("Введите букву, соответствующую выбранному варианту:\n");
	printf ("a. совет         b. звонок\n");
	printf ("c. подсчет       q. выход\n");
	ch = get_first ();
	while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q')
	{
		printf ("Выберите a, b, c или q.\n");
		ch = get_first ();
	}

	return ch;
}

char get_first (void)
{
	int ch;

	ch = getchar ();
	while (getchar () != '\n')
		;

	return ch;
}

int get_int (void)
{
	long input;
	char ch;				/* лучше использовать int, getchar может вернуть -1 */

	while (scanf ("%d", &input) != 1)
	{
		while ((ch = getchar ()) != '\n')
			putchar (ch);	/* "отбросить некорректный ввод" с выводом на терминал */
		printf (" не является целочисленным.\nВведите "
				"целое число, такое как 25, -178 или 3: ");
	}
	return input;
}

/*
$ ./menuette 
Введите букву, соответствующую выбранному варианту:
a. совет         b. звонок
c. подсчет       q. выход
a
Покупайте дешево, продавайте дорого.
Введите букву, соответствующую выбранному варианту:
a. совет         b. звонок
c. подсчет       q. выход
b
Введите букву, соответствующую выбранному варианту:
a. совет         b. звонок
c. подсчет       q. выход
c
До какого предела вести подсчет? Введите целое число:
4
1
2
3
4
Введите букву, соответствующую выбранному варианту:
a. совет         b. звонок
c. подсчет       q. выход
f
Выберите a, b, c или q.
c
До какого предела вести подсчет? Введите целое число:
tratata
tratata не является целочисленным.
Введите целое число, такое как 25, -178 или 3: 2
1
2
Введите букву, соответствующую выбранному варианту:
a. совет         b. звонок
c. подсчет       q. выход
q
Програма завершена.
*/