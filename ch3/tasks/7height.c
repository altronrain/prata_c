/* 7height.c -- преобразование роста из сантиметров в дюймы */
#include <stdio.h>

int main(void)
{
    float h;
    float duim = 2.54;

    printf("Введите свой рост в сантиметрах: ");
    if(scanf("%f", &h) != 1)
    {
        fprintf(stderr, "Введено некорректное значение\n");
        return 1;
    }
    printf("Ваш рост составляет %f в дюймах!\n", h / duim);
    return 0;
}