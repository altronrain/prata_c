/* 4float_format.c -- вывод числа с плавающей точкой в разных форматах */

#include <stdio.h>

int main(void)
{
    float num;

    printf("Введите значение с плавающей точкой: ");
    if (scanf("%f", &num) != 1)
    {
        fprintf(stderr, "Введено некорректное значение.\n");
        return 1;
    }
    printf("Запись с фиксированной точкой: %f\n", num);
    printf("Экспоненциальная форма записи: %e\n", num);
    printf("Двоично-экспоненциальное представление: %a\n", num);
    return 0;
}