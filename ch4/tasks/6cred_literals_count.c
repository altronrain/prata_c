/* 6cred_literals_count.c -- вывод имени и фамилии с подсчетом количества символов */
/*
Напишите программу, которая запрашивает имя пользователя и его фамилию.
Сделайте так, чтобы она выводила введенные имена в одной строке и количество
символов в каждом слове в следующей строке. Выровняйте каждое количество символов
по окончанию соответствующего имени, как показано ниже:

Ivan Petrov
   4      6

Затем сделайте так, чтобы программа выводила ту же самую информацию, но с 
количеством символов, выровненным по началу каждого слова:

Ivan Petrov
4    6
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[40];
	char surname[50];
	int n_len, s_len;

	printf("Введите ваше имя и фамилию через пробел:\n");
	scanf("%39s %49s", name, surname);

	n_len = strlen(name);
	s_len = strlen(surname);

	printf("Получилось следующее:\n");
	printf("%s %s\n", name, surname);
	printf("%*d %*d\n", n_len, n_len, s_len, s_len);
	printf("%s %s\n", name, surname);
	printf("%-*d %-*d\n", n_len, n_len, s_len, s_len);

	return 0;
}

/*
$ ./6cred_literals_count 
Введите ваше имя и фамилию через пробел:
Kirill Komarov
Получилось следующее:
Kirill Komarov
     6       7
Kirill Komarov
6      7
*/