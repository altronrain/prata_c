/* append.c  -- добавление содержимого файлов в файл назначения */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append (FILE *source, FILE *dest);
char *s_gets (char *st, int n);

int main (void)
{
	FILE *fa, *fs;		/* fa - файл назначения, fs - исходный файл */
	int files = 0;
	char file_app[SLEN];	/* имя файла назначения */
	char file_src[SLEN];	/* имя исходного файла */
	int ch;

	puts ("Enter resulting filename:");
	s_gets (file_app, SLEN);

	if ((fa = fopen (file_app, "a+")) == NULL) {	/* не двоичный режим */
		fprintf (stderr, "Cannot open file %s\n", file_app);
		exit (EXIT_FAILURE);
	}

	if (setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0) {
		fputs ("Cannot create output custom buffer\n", stderr);
		exit (EXIT_FAILURE);
	}

	puts ("Enter the name of the first source file (or empty to quit):");

	while (s_gets (file_src, SLEN) && file_src[0] != '\0') {
		if (strcmp (file_src, file_app) == 0)
			fputs ("Cannot append file to itself\n", stderr);
		else if ((fs = fopen (file_src, "r")) == NULL)	/* не двоичный режим */
			fprintf (stderr, "Cannot open file %s\n", file_src);
		else {
			if (setvbuf (fs, NULL, _IOFBF, BUFSIZE) != 0) {
				fputs ("Cannot create input custom buffer\n",
				       stderr);
				continue;
			}

			append (fs, fa);

			if (ferror (fs) != 0)
				fprintf (stderr, "Error reading file %s.\n",
					 file_src);
			if (ferror (fa) != 0)
				fprintf (stderr, "Error writing to file %s.\n",
					 file_app);

			fclose (fs);
			files++;
			printf ("Contents of file %s appended.\n", file_src);
			puts ("Enter the name of the first source file (or empty to quit):");
		}
	}

	printf ("Done appending. Quantity of processed files: %d.\n", files);
	rewind (fa);
	printf ("Content of resulting file %s:\n", file_app);

	while ((ch = getc (fa)) != EOF)
		putchar (ch);

	puts ("Done.");
	fclose (fa);

	return 0;
}

void append (FILE *source, FILE *dest)	/* копирование блоками по 4096 символов */
{
	size_t bytes;
	static char temp[BUFSIZE];	/* выделить память один раз */

	while ((bytes = fread (temp, sizeof (char), BUFSIZE, source)) > 0)
		fwrite (temp, sizeof (char), bytes, dest);
}

char *s_gets (char *st, int n)		/* предотвращение попадания пустых символов и '\n' в имена файлов */
{
	char *ret_val;
	char *find;

	ret_val = fgets (st, n, stdin);

	if (ret_val) {
		find = strchr (st, '\n');	/* поиск символа новой строки */

		if (find)			/* если нашелся */
			*find = '\0';		/* помеситить по указанному адресу нулевой символ */
		else				/* st[i] = '\0'; сброс остального буфера */
			while (getchar () != '\n')
				continue;
	}

	return ret_val;
}

/*
$ ./append 
Enter resulting filename:
append_filename
Enter the name of the first source file (or empty to quit):
eddy
Contents of file eddy appended.
Enter the name of the first source file (or empty to quit):
wordy
Contents of file wordy appended.
Enter the name of the first source file (or empty to quit):

Done appending. Quantity of processed files: 2.
Content of resulting file append_filename:
So even Eddy came oven ready.
Under
this
moon
and
star
we
are
welcome
you
outlander
Filthy
N'wah!
Done.
*/