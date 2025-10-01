#include <stdio.h>

void smile(void);

int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");

    return 0;
}

void smile(void)
{
    printf("Улыбайся!");
}


/*

int main(void)
{
    char str[] = "Улыбайся!";

    printf("%s\n", str * 3);
    printf("%s\n", str * 2);
    printf("%s\n", str);

    return 0;
}

*/