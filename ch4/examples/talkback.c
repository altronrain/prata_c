/* talkback.c -- любопытная информативная программа */
#include <stdio.h>
#include <string.h>     /* предоставляет прототип strlen() */

#define DENSITY 62.4    /* удельная масса человека в фунтах на кубический фут */

int main(void)
{
    float weight, volume;
    int size, letters;
    char name[40];          /* name -- массив из 40 символов */

    printf("Здраствуйте! Как вас зовут?\n");
    scanf("%s", name);
    printf("%s, сколько вы весите в фунтах?\n", name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Хорошо, %s, ваш объем составляет %2.2f кубических футов.\n",
        name, volume);
    printf("К тому же ваше имя состоит из %zd букв, \n", letters);  /* sizeof и strlen корректнее z модификатор */
    printf("и мы располагаем %d байтами для его сохранения.\n", size);

    return 0;
}