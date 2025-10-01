#include <stdio.h>

int main(void)
{
    char *str = "Улыбайся!";

    printf("%s%s%s\n", str, str, str);
    printf("%s%s\n", str, str);
    printf("%s\n", str);

    return 0;
}