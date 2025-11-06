/* float_overflow.c -- UB при переполнении переменной типа с плавающей точкой. printf() выводит inf */
#include <stdio.h>

int main(void)
{

    float toobig = 3.4E38 * 100.0f;

    /* Выведет специальное значение `inf` или `infinity` */
    printf("%e\n", toobig);

    return 0;
}

/*
$ ./float_overflow 
inf
*/