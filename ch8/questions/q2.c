/* q2.c -- что выполнят следующие операторы */
#include <stdio.h>

int main(void)
{

	putchar ('H');		/* Вывод на терминал прописной английской буквы H */
	putchar ('\007');	/* bell \a */
	putchar ('\n');		/* Перенос строки на терминале */
	putchar ('\b');		/* backspace */


	return 0;
}

/*
$ ./q2 
H
*/