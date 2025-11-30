/* q4.c -- программа с ошибками

define B booboo
define X 10

main (int)
{
    int age;
    char name;

    printf("DВведите свое имя.");
    scanf("%s", name);
    printf("Хорошо, %C, а сколько вам лет?\n", name);
    scanf("%f", age);
    xp = age + X;
    printf("Неужели, %s! Вам должно быть, по меньшей мере, %d.\n", B, xp);
    return 0;
}

*/

#include <stdio.h>

#define B "booboo"
#define X 10

int main(void)
{
    int age, xp;
    char name[40];

    printf("Введите свое имя.\n");
    scanf("%39s", name);
    printf("Хорошо, %s, а сколько вам лет?\n", name);
    scanf("%d", &age);
    xp = age + X;
    printf("Неужели, %s! Вам должно быть, по меньшей мере, %d.\n", B, xp);
    return 0;
}