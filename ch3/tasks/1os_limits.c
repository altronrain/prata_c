/* 1oslimits.c -- проверка обработки операционной системой переполнений и потерь значимости */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float num1, res1, num2, res2;
    num1 = FLT_MAX;
    res1 = FLT_MAX * 50.0f;
    num2 = FLT_MIN;
    res2 = num2 / 10.0;


    printf("Целочисленное переполнения: %d + 1 = %d\n", INT_MAX, INT_MAX + 1);
    printf("Переполнение чисел с плавающей точкой: %e ^2 = %e\n", DBL_MAX, DBL_MAX * DBL_MAX);
    printf("Переполнение чисел с плавающей точкой: %e * 50.0f = %e\n", num1, res1);
    /* printf("Потеря значимости: %f / 2.0 = %f\n", DBL_MIN, DBL_MIN / 10.0); */
    printf("Потеря значимости: %f / 10.0 = %f\n", 0.123456f, 0.123456f / 10.0f);
    printf("Потеря значимости: %e / 10.0 = %e\n", num2, res2);
    printf("Потеря значимости: %e / %e = %e\n", DBL_MIN, DBL_MAX, DBL_MIN / DBL_MAX);
    printf("Потеря значимости: %e / 2 = %e\n", DBL_MIN, DBL_MIN / 2);

    return 0;
}