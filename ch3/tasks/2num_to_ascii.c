/* 2numtoascii.c -- преобразование числа в соответствующий печатный символ ASCII */
/*
#include <stdio.h>

int main(void)
{
    char num;

    printf("Введите код ASCII: ");
    scanf("%d", &num);
    printf("%zd\n", sizeof(num));
    printf("Соответствующий имвол из таблицы ASCII: %c\n", num);

    return 0;
}
*/

#include <stdio.h>

int main(void)
{
    int num;

    printf("Введите код ASCII: ");
    if (scanf("%d", &num) != 1)
    {
        fprintf(stderr, "Введено некорректное значение.\n");
        return 1;
    }
    if (num < 32 || num >= 127)
    {
        fprintf(stderr, "Введен код непечатного символа ");
        fprintf(stderr, "или число за пределами таблицы ASCII.\n");
        return 2;
    }
    fprintf(stderr, "Соответствующий имвол из таблицы ASCII: %c\n", num);
    return 0;
}