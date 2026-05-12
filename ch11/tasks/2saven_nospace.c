/* 2saven_nospace.c  -- запись последовательности символов в массив

Модифицируйте и протестируйте функцию из упражнения 1, обеспечив в ней
прекращение ввода после n символов либо при достижении первого символа пробела,
табуляции или новой строки, в зависимости от того, что произойдет раньше.
(Не ограничивайтесь только использованием scanf().)
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 51

void getns (char * st, int n);

int main (void)
{
	char try[SIZE];

	puts ("Input a string:");
	getns (try, 8);

	printf ("String: %s\n", try);

	return 0;
}

void getns (char * st, int n)
{
	int res;

	for (int i = 0; i < n; i++, st++) {
		if ((res = getchar ()) == EOF || isspace(res))
			break;

		*st = res;
	}
}
/*
$ ./2saven_nospace 
Input a string:
Gary Mary
String: Gary
✔ ~/Documents/repos/prata_c/ch11/tasks [main|…9] 
$ ./2saven_nospace 
Input a string:
Summer  Autumn
String: Summer
✔ ~/Documents/repos/prata_c/ch11/tasks [main|…9] 
$ ./2saven_nospace
Input a string:
GaryString: Gary		<-- EOF Ctrl+D
*/