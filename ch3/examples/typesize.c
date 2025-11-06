/* typesize.c -- вывод размеров типов в системе */
#include <stdio.h>

int main(void)
{

    /* Спецификатор %zd доступен начиная с C99 */
    printf("Тип short имеет размер %zd байт(ов).\n", sizeof(short));
    printf("Тип int имеет размер %zd байт(ов).\n", sizeof(int));
    printf("Тип char имеет размер %zd байт(ов).\n", sizeof(char));
    printf("Тип long имеет размер %zd байт(ов).\n", sizeof(long));
    printf("Тип long long имеет размер %zd байт(ов).\n", sizeof(long long));
    printf("Тип double имеет размер %zd байт(ов).\n", sizeof(double));
    printf("Тип long double имеет размер %zd байт(ов).\n", sizeof(long double));

    return 0;
}

/*
$ ./typesize 
Тип short имеет размер 2 байт(ов).
Тип int имеет размер 4 байт(ов).
Тип char имеет размер 1 байт(ов).
Тип long имеет размер 8 байт(ов).
Тип long long имеет размер 8 байт(ов).
Тип double имеет размер 8 байт(ов).
Тип long double имеет размер 16 байт(ов).
*/