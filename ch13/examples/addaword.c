/* addaword.c -- использование fprintf(), fscanf() и rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main (void)
{
	FILE *fp;
	char words[MAX];

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf (stdout, "Cannot open file \"wordy\".\n");
		exit (EXIT_FAILURE);
	}

	puts ("Enter words to add them into file; for exit");
	puts ("Enter symbol '#' at the beginning of the word.");

	while ((fscanf (stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf (fp, "%s\n", words);

	puts ("File content:");
	rewind (fp);	/* возврат "курсора" в начало файла */

	while (fscanf (fp, "%s", words) == 1)
		puts (words);

	puts ("Done!");

	if (fclose (fp) != 0)
		fprintf (stderr, "Error on file closing\n");

	return 0;
}
/*
$ ./addaword 
Enter words to add them into file; for exit
Enter symbol '#' at the beginning of the word.
Under this moon and star we are welcome you outlander #
File content:
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
Done!

20:12 $ ./addaword 
Enter words to add them into file; for exit
Enter symbol '#' at the beginning of the word.
Filthy N'wah! #
File content:
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
Done!
*/