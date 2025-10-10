/* 6water_mol.c -- подсчет количества молекул воды в заданном объеме */
#include <stdio.h>

int main(void)
{
    float n;
    float mol = 3.e-24;

    printf("Введите объем воды в квартах: ");
    if(scanf("%f", &n) != 1)
    {
        fprintf(stderr, "Введено некорректное значение\n");
        return 1;
    }
    printf("В таком объеме воды содержится %e молекул воды!\n", n * 950.00 / mol);
    return 0;
}