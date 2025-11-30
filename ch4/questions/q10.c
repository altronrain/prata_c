/* q9.c -- исправить ошибку

В чем заключается ошибка в следующем операторе и как ее можно исправить?

printf("Тип double состоит из %z байтов..\n", sizeof (double));

*/

#include <stdio.h>

int main(void)
{

    printf("Тип double состоит из %zd байтов..\n", sizeof (double));

    return 0;
}

/*
$ ./q10
Тип double состоит из 8 байтов..
*/