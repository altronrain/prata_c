/* praise2.c */
#include <stdio.h>
#include <string.h>     /* предоставляет прототип strlen() */

#define PRAISE "Вы - выдающаяся личность."

int main(void)
{
    char name[40];

    printf("Как вас зовут? ");
    scanf("%s", name);              /* считывание до первого пробельного символа */
    printf("Здравствуйте, %s. %s\n", name, PRAISE);
    printf("Ваше имя состоит из %zd символов и занимает %zd ячеек памяти.\n",
        strlen(name), sizeof name);
    printf("Хвалебная фраза содержит %zd символов", strlen(PRAISE));
    printf(" и занимает %zd ячеек памяти.\n", sizeof PRAISE);
    /* Более менее корректное считывание любых символов кроме перевода строки:
    if (scanf("%39[^\n]%*c", name) == 1)
    {
        printf("Здравствуйте, %s. %s\n", name, PRAISE);
    }
    А еще лучше использовать fgets()
    */
    return 0;
}