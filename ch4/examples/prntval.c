/* prntval.c -- выяснение возвращаемого значения функции printf() */
#include <stdio.h>

int main(void)
{
    int bch20 = 100;
    int rv;

    rv = printf("Вода закивает при %d градусах по Цельсию.\n", bch20);
    printf("Функция printf() вывела %d символов.\n", rv);


    return 0;
}

/*
$ ./prntval 
Вода закивает при 100 градусах по Цельсию.
Функция printf() вывела 75 символов.
*/