/* q9.c -- считывание данных

Для каждой из следующих входных строк напишите опреатор scanf(), чтобы прочитать их.
Объявите также переменные или массивы, используемые в операторе.

- 101
- 22.32 8.34E-09
- linguini
- catch 22
- catch 22 (но пропустить catch)

*/

#include <stdio.h>

int main(void)
{
    int num1;
    float num2, num3;
    char str1[10];

    scanf("%d", &num1);
    printf("[%d]\n", num1);
    scanf("%f %E", &num2, &num3);
    printf("[%.2f][%.2E]\n", num2, num3);
    scanf("%9s", str1);
    printf("[%s]\n", str1);
    scanf("%9s %d", str1, &num1);
    printf("[%s][%d]\n", str1, num1);
    scanf("%*s %d", &num1);
    printf("[%d]\n", num1);

    return 0;
}

/*
$ ./q9
101
[101]
22.32 8.34E-09
[22.32][8.34E-09]
linguini
[linguini]
catch 22
[catch][22]
catch 22
[22]
*/