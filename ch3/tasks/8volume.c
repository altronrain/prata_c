/* 8volume.c -- вывод объема в разных величинах */
#include <stdio.h>

int main(void)
{
    float n;

    printf("Введите объем в чашках (c.): ");
    if(scanf("%f", &n) != 1)
    {
        fprintf(stderr, "Введено некорректное значение\n");
        return 1;
    }
    printf("В пинтах (pt.) это: %f\n", n / 2.00);
    printf("В унциях (fl oz.) это: %f\n", n * 8.00);
    printf("В столовых ложках (tblsp.) это: %f\n", n * 16.00);
    printf("В чайных ложках (tsp.) это: %f\n", n * 48.00);

    return 0;
}