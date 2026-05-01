/* repeat.c  -- функция main() с аргументами */
#include <stdio.h>

int main (int argc, char *argv[])	/* int argc, char **argv -- более распространенная форма */
{
	int count;

	printf ("Количество аргументов, указанных в командной строке: %d\n",
		argc - 1);

	for (count = 1; count < argc; count++)
		printf ("%d: %s\n", count, argv[count]);

	printf ("\n");

	return 0;
}
/*
$ ./repeat some text
Количество аргументов, указанных в командной строке: 2
1: some
2: text

$ ./repeat "I have been" there
Количество аргументов, указанных в командной строке: 2
1: I have been
2: there
*/