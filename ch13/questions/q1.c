/* q1.c  -- программа с ошибками

Что неправильно в следующей программе?

int main (void)
{
	int *fp;
	int k;

	fp = fopen ("gelatin");
	for (k = 0; k < 30; k++)
		fputs(fp, "Кто-то есть студень.");
	fclose("gelatin");
	return 0;
}
*/
#include <stdio.h>

int main (void)
{
	FILE *fp;
	int k;

	fp = fopen ("gelatin", "w");

	for (k = 0; k < 30; k++)
		fputs ("Кто-то есть студень.", fp);

	fclose (fp);

	return 0;
}

/*
$ ./q8 
color in main() is B
color in first() is R
color in main() is B
color in second() is G
color in main() is B
*/