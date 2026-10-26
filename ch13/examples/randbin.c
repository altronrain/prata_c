/* randbin.c  -- произвольный доступ, двоичный ввод-вывод */
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main (void)
{
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;

	for (i = 0; i < ARSIZE; i++)	/* заполнение массива double */
		numbers[i] = 100.0 * i + 1.0 / (i + 1);

	if ((iofile = fopen (file, "wb")) == NULL) {
		fprintf (stderr, "Cannot open file %s for writing.\n", file);
		exit (EXIT_FAILURE);
	}

	fwrite (numbers, sizeof (double), ARSIZE, iofile);
	fclose (iofile);

	if ((iofile = fopen (file, "rb")) == NULL) {
		fprintf (stderr, "Cannot open file %s for reading.\n", file);
		exit (EXIT_FAILURE);
	}

	printf ("Enter index (0-%d).\n", ARSIZE - 1);

	while (scanf ("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
		pos = (long) i* sizeof (double);	/* вычисление смещения */
		fseek (iofile, pos, SEEK_SET);		/* переход в указанную позицию */
		fread (&value, sizeof (double), 1, iofile);
		printf ("The index contains value %f.\n", value);
		puts ("Enter next index or out of bounds value for exit:");
	}

	fclose (iofile);
	puts ("Done.");

	return 0;
}

/*
$ ./randbin 
Enter index (0-999).
83
The index contains value 8300.011905.
Enter next index or out of bounds value for exit:
44
The index contains value 4400.022222.
Enter next index or out of bounds value for exit:
999
The index contains value 99900.001000.
Enter next index or out of bounds value for exit:
-1
Done.
*/