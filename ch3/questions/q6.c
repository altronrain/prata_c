/* q6.c -- отображение разных типов данных */
#include <stdio.h>

#define TYPE_NAME(x) _Generic((x), \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short: "short", \
    unsigned short: "unsigned short", \
    int: "int", \
    unsigned int: "unsigned int", \
    long: "long", \
    unsigned long: "unsigned long", \
    long long: "long long", \
    unsigned long long: "unsigned long long", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    default: "unknown")

int main(void)
{
    /* Указан тип в операторе объявления. Через | указан тип самой константы */
    printf("Константа %d имеет тип %s\n", 12, TYPE_NAME(12));                 /* int */
    printf("Константа %#x имеет тип %s\n", 0X3, TYPE_NAME(0X3));              /* int */
    printf("Константа %c имеет тип %s\n", 'C', TYPE_NAME('C'));               /* char|int */
    printf("Константа %e имеет тип %s\n", 2.34E07, TYPE_NAME(2.34E07));      /* float|double */
    printf("Константа %c имеет тип %s\n", '\040', TYPE_NAME('\040'));         /* char */
    printf("Константа %f имеет тип %s\n", 7.0, TYPE_NAME(7.0));               /* float|double */
    printf("Константа %ld имеет тип %s\n", 6L, TYPE_NAME(6L));                /* long int */
    printf("Константа %f имеет тип %s\n", 6.0f, TYPE_NAME(6.0f));             /* float */
    printf("Константа %a имеет тип %s\n", 0x5.b6p12, TYPE_NAME(0x5.b6p12));  /* float|double */

    return 0;
}

/*
$ ./q6
Константа 12 имеет тип int
Константа 0x3 имеет тип int
Константа C имеет тип int
Константа 2.340000e+07 имеет тип double
Константа   имеет тип int
Константа 7.000000 имеет тип double
Константа 6 имеет тип long
Константа 6.000000 имеет тип float
Константа 0x1.6d8p+14 имеет тип double
*/