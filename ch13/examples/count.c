// count.c  -- использование стандартного ввода-вывода
#include <stdio.h>
#include <stdlib.h>		// exit()

int main (int argc, char *argv[])
{
	int ch;			// место для хранения каждого символа по мере чтения
	FILE *fp;		// "указатель файла"
	unsigned long count = 0;

	if (argc != 2) {
		printf ("Usage: %s file_name\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	if ((fp = fopen (argv[1], "r")) == NULL) {
		printf ("Could not open %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		putc (ch, stdout);	// то же, что и putchar(ch)
		count++;
	}

	fclose (fp);
	printf ("\n");
	printf ("File %s consists of %lu symbols\n", argv[1], count);

	return 0;
}

/*
$ ./count
Usage: ./count file_name

$ ./count count.c 
// count.c  -- использование стандартного ввода-вывода
#include <stdio.h>
#include <stdlib.h>             // exit()

int main (int argc, char *argv[])
{
        int ch;                 // место для хранения каждого символа по мере чтения
        FILE *fp;               // "указатель файла"
        unsigned long count = 0;

        if (argc != 2) {
                printf ("Usage: %s file_name\n", argv[0]);
                exit (EXIT_FAILURE);
        }

        if ((fp = fopen (argv[1], "r")) == NULL) {
                printf ("Could not open %s\n", argv[1]);
                exit (EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF) {
                putc (ch, stdout);      // то же, что и putchar(ch)
                count++;
        }

        fclose (fp);
        printf ("\n");
        printf ("File %s consists of %lu symbols\n", argv[1], count);

        return 0;
}

File count.c consists of 775 symbols
*/