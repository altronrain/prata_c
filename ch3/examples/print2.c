/* print2.c -- дополнительные свойства функции printf() */
#include <stdio.h>

int main(void)
{

    unsigned int un = 3000000000;   /* система с 32-битным типом int */
    short end = 200;                /* и 16-битным типом short */
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u, но не %d\n", un, un);
    printf("end = %hd и %d\n", end, end);
    printf("big = %ld, но не %hd\n", big, big);
    printf("verybig = %lld, но не %ld\n", verybig, verybig); /* тут будет разница только на описанной системе */

    return 0;
}

/*
$ ./print2 
un = 3000000000, но не -1294967296
end = 200 и 200
big = 65537, но не 1
verybig = 12345678908642, но не 12345678908642
*/