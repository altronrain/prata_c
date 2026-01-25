/* q10.c -- Что бы выводили фрагменты кода

int x = 0;
while (++x < 3)
	printf("%4d", x);			1	2

int x = 100;
while (x++ < 103)
printf("%4d\n", x);
printf("%4d\n", x);				101\n102\n103\n104

char ch = 's';
while (ch < 'w')
{
	printf("%c", ch);
	ch++;
}
printf("%c\n", ch);				stuvw

*/
#include <stdio.h>

int main(void)
{
	int x = 0;
	int y = 100;
	char ch = 's';

	while (++x < 3)
		printf("%4d", x);

	printf("\n");

	while (y++ < 103)
	printf("%4d\n", y);
	printf("%4d\n", y);

	while (ch < 'w')
	{
		printf("%c", ch);
		ch++;
	}
	printf("%c\n", ch);

	return 0;
}

/*
$ ./q10
   1   2
 101
 102
 103
 104
stuvw
*/