/* q7.c -- отображение разных типов данных. Int принимаем как 16-бит */
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
    /* Указан тип в операторе объявления. Через | указан тип самой константы
    Int принимаем за 16-бит
    */
    printf("Константа %#o имеет тип %s\n", 012, TYPE_NAME(012));            /* int */
    printf("Константа %Le имеет тип %s\n", 2.9e05L, TYPE_NAME(2.9e05L));    /* long double */
    printf("Константа %c имеет тип %s\n", 's', TYPE_NAME('s'));             /* char|int*/
    printf("Константа %ld имеет тип %s\n", 100000, TYPE_NAME(100000));      /* long int */
    printf("Константа %c имеет тип %s\n", '\n', TYPE_NAME('\n'));           /* char|int */
    printf("Константа %f имеет тип %s\n", 20.0, TYPE_NAME(20.0));           /* float|double */
    printf("Константа %#x имеет тип %s\n", 0x44, TYPE_NAME(0x44));          /* int */
    printf("Константа %d имеет тип %s\n", -40, TYPE_NAME(-40));             /* int */

    return 0;
}

/*
$ ./q7 
Константа 012 имеет тип int
Константа 2.900000e+05 имеет тип long double
Константа s имеет тип int
Константа 100000 имеет тип int
Константа 
 имеет тип int
Константа 20.000000 имеет тип double
Константа 0x44 имеет тип int
Константа -40 имеет тип int
*/