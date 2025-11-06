/* intconv.c  -- несоответствия при преобразовании целочисленных типов */
#include <stdio.h>

#define PAGES 336
#define WORDS 65618

int main(void)
{
    short num = PAGES;
    short mnum = -PAGES;

    printf("num как тип short и тип unsigned short: %hd %hu\n", num, num);
    printf("-num как тип short и тип unsigned short: %hd %hu\n", mnum, mnum);       /* для %u будет выведено "некорректное" значение */
    printf("num как тип int и тип char: %d %c\n", num, num);                        /* для %c будет просмотрен только первый байт из двух (mod 256) */
    printf("WORDS как тип int, short и char: %d %hd %c\n", WORDS, WORDS, WORDS);    /* %hd то же самое (mod 65536) */

    return 0;
}

/*
$ ./intconv 
num как тип short и тип unsigned short: 336 336
-num как тип short и тип unsigned short: -336 65200
num как тип int и тип char: 336 P
WORDS как тип int, short и char: 65618 82 R
*/