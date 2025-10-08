/* escape.c -- некорректное количество аргументов в форматированном выводе */
#include <stdio.h>

int main(void)
{
    float salary;

    printf("\aВведите желаемую сумму месячной зарплаты:");          /* 1 */
    printf(" $________\b\b\b\b\b\b\b\b");                           /* 2 */
    scanf("%f", &salary);
    printf("\t$%.2f в месяц соответствует $%.2f в год.", salary,
        salary * 12.0);                                             /* 3 */
    printf("\rОго!\n");                                             /* 4 */

    return 0;
}