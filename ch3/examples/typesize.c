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