/* q10.c -- программа с ошибками 

void main(int) / эта программа безупречна /
{

    cows, legs integer;

    printf("Сколько коровьих ног вы насчитали?\n);
    scanf("%c", legs);
    cows = legs / 4;
    printf("Отсюда следует, что есть %f коров(а).\n", cows)

}

*/
#include <stdio.h>

int main(void) /* эта программа безупречна */
{

    float cows, legs;

    printf("Сколько коровьих ног вы насчитали?\n");
    scanf("%f", &legs);
    cows = legs / 4;
    printf("Отсюда следует, что есть %f коров(а).\n", cows);

}