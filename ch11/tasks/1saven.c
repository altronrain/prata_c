/* 1saven.c  -- запись последовательности символов в массив

Разработайте и протестируйте функцию, которая извлекает из ввода следующие
n символов (включая символы пробела, табуляции и новой строки), сохраняя
результаты в массиве, адрес которого передается в качестве аргумента.
*/
#include <stdio.h>
#define SIZE 51

void getns (char * st, int n);

int main (void)
{
	char try[SIZE];

	puts ("Input a string:");
	getns (try, 8);

	printf ("String: %s", try);

	return 0;
}

void getns (char * st, int n)
{
	int res;

	for (int i = 0; i < n; i++, st++) {
		if ((res = getchar ()) == EOF)
			break;

		*st = res;
	}
}
/*
$ ./1saven 
Input a string:
GarString: Gar✔ ~/Documents/repos/prata_c/ch11/tasks [main|…9] 
$ ./1saven 
Input a string:
Gary
Mary
String: Gary
Mar✔ ~/Documents/repos/prata_c/ch11/tasks [main|…9] 
*/