/* 1credentials.c -- запрос и вывод имени и фамилии */
/*
Напишите программу, которая запрашивает имя и фамилию, а затем
выводит их в формате фамилия, имя
*/
#include <stdio.h>

int main(void)
{
	char name[40];
	char surname[50];

	printf("Введите ваше имя:\n");
	scanf("%39s", name);
	printf("Введите вашу фамилию:\n");
	scanf("%49s", surname);
	printf("Введенные фамилия и имя: %s, %s\n", surname, name);

	return 0;
}

/*
$ ./1credentials 
Введите ваше имя:
Kirill
Введите вашу фамилию:
Komarov
Введенные фамилия и имя: Komarov, Kirill
*/