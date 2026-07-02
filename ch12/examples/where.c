/* where.c  -- типы памяти под разные методы выделения */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";

int main (void)
{
	int auto_store = 40;
	char auto_string[] = "Automatic array of char";
	int *pi;
	char *pcl;

	pi = (int *) malloc (sizeof (int));
	*pi = 35;
	pcl = (char *) malloc (strlen ("Dynamic string literal") + 1);
	strcpy (pcl, "Dynamic string literal");

	printf ("static_store: %d by address %p\n", static_store, &static_store);
	printf ("  auto_store: %d by address %p\n", auto_store, &auto_store);
	printf ("         *pi: %d by address %p\n", *pi, pi);
	printf ("%s by address %p\n", pcg, pcg);
	printf ("%s by address %p\n", auto_string, auto_string);
	printf ("%s by address %p\n", pcl, pcl);
	printf ("%s by address %p\n", "String in quotes", "String in quotes");

	free (pi);
	free (pcl);

	return 0;
}
/*
$ ./where 
static_store: 30 by address 0x5614067c7028
  auto_store: 40 by address 0x7ffe79960efc
         *pi: 35 by address 0x56142f5c12a0
String Literal by address 0x5614067c5008
Automatic array of char by address 0x7ffe79960ee0
Dynamic string literal by address 0x56142f5c12c0
String in quotes by address 0x5614067c508a
*/
/*
По адресам видно (хоть и хуже чем хотелось бы), что тут 3 области:

- для статических данных
- для автоматических данных
- для динамических данных (куча)
*/