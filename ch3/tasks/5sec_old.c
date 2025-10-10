/* 5old_in_seconds.c -- преобразование возраста из лет в секунды */

#include <stdio.h>

int main(void)
{
    float years;
    float y_sec = 3.156e7;

    printf("Введите свой полный возраст в годах: ");
    if(scanf("%f", &years) != 1)
    {
        fprintf(stderr, "Введено некорректное значение\n");
        return 1;
    }
    printf("А в секундах это целых %f секунд!\n", years * y_sec);
    return 0;
}