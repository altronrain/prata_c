/* q5.c -- вывод программы

Что выведет следующая программа?

#include <stdio.h>
int main(void)
{
	int num;
	for (num = 1; num <= 11; num++)
	{
		if (num % 3 == 0)
			putchar ('$');
		else
			putchar ('*');
			putchar ('#');
		putchar ('%');
	}
	putchar ('\n');

	return 0;
}
*/
#include <stdio.h>

int main(void)
{
	int num;
	for (num = 1; num <= 11; num++)	/* *#%*#%$#%*#%*#%$#%*#%*#%$#%*#%*#%\n*/
	{
		if (num % 3 == 0)
			putchar ('$');
		else
			putchar ('*');
			putchar ('#');			/* эта функция вне if-блока! */
		putchar ('%');
	}
	putchar ('\n');

	return 0;
}

/*
$ ./q5 
*#%*#%$#%*#%*#%$#%*#%*#%$#%*#%*#%
*/