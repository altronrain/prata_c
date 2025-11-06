/* q8.c -- подбор спецификаторов для printf() */
#include <stdio.h>

int main(void)
{

    int imate = 2;
    long shot = 53456;
    char grade = 'A';
    float log = 2.71828;

    printf("Шансы попасть в %d были %ld к 1.\n", imate, shot);
    printf("Счет %f не соответствует уровню %c.\n", log, grade);

    return 0;
}

/*
$ ./q8 
Шансы попасть в 2 были 53456 к 1.
Счет 2.718280 не соответствует уровню A.
*/