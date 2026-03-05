/* swap2.c -- проблема реализации функции обмена значениями без указателей */
#include <stdio.h>

void interchange (int u, int v);

int main (void)
{
	int x = 5, y = 10;

	printf ("Первоначально x = %d и y = %d.\n", x, y);
	interchange (x , y);
	printf ("Теперь x = %d и y = %d.\n", x, y);

	return 0;
}

/* необходимо вернуть 2 значения, а return может только одно
- либо применять массив как одну переменную для возврата (или структуру)
- либо применять указатели
*/
void interchange (int u, int v)
{
	int temp;

	printf ("Первоначально u = %d и v = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf ("Теперь u = %d и v = %d.\n", u, v);
}

/*
$ ./swap2 
Первоначально x = 5 и y = 10.
Первоначально u = 5 и v = 10.
Теперь u = 10 и v = 5.
Теперь x = 5 и y = 10.
*/