/* q6.c -- Что выведет эта программа

#include <stdio.h>
#define FORMAT "%s! C is cool!\n"

int main(void)
{
	int num = 10;

	printf(FORMAT, FORMAT);			%s! C is cool!\n! C is cool!\n"
	printf("%d\n", ++num);			print -- 11; num -- 11
	printf("%d\n", num++);			print -- 11; num -- 12
	printf("%d\n", num--);			print -- 12; num -- 11
	printf("%d\n", num);			print -- 11

	return 0;
}

*/
#include <stdio.h>
#define FORMAT "%s! C is cool!\n"

int main(void)
{
	int num = 10;

	printf(FORMAT, FORMAT);
	printf("%d\n", ++num);
	printf("%d\n", num++);
	printf("%d\n", num--);
	printf("%d\n", num);

	return 0;
}

/*
$ ./q6
%s! C is cool!
! C is cool!
11
11
12
11
*/