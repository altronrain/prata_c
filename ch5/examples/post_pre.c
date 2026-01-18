/* post_pre.c  -- постфиксная и префиксная формы инкремена */
#include <stdio.h>

int main(void)
{
	int a = 1, b = 1;
	int a_post, b_pre;

	/* Постфиксная форма -- переменная 'a' меняется после использования ее значения */
	a_post = a++;
	/* Префиксная форма -- переменная 'b' меняется до использования ее значения */
	b_pre  = ++b;
	printf("a\ta_post\tb\tb_pre\n");
	printf("%d\t%d\t%d\t%d\n", a, a_post, b, b_pre);

	return 0;
}

/*
$ ./post_pre 
a       a_post  b       b_pre
2       1       2       2
*/