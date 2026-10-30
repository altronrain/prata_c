/* q3.c  -- дополнить операторы

Предположим, что в программе имеются следующие операторы:

#include <stdio.h>
FILE *fp1, *fp2;
char ch;
fp1 = fopen ("terky", "r");
fp1 = fopen ("jerky", "w");

Кроме того, предположим, что оба файла были успешно открыты. Добавьте
недостающие аргументы в следующие вызовы функций:

ch = getc();
fprintf( , "%c\n", );
putc( , );
fclose(); // закрыть файл terky
*/
#include <stdio.h>

int main (void)
{
	FILE *fp1, *fp2;
	char ch;

	fp1 = fopen ("terky", "r");
	fp2 = fopen ("jerky", "w");

	while ((ch = getc (fp1)) != EOF) {
		/* вероятно требовали: fprintf (fp2, "%c\n", ch); */
		fprintf (stdout, "%c\n", ch);
		putc (ch, fp2);
	}

	fclose (fp1);
	fclose (fp2);

	return 0;
}

/*
$ ./q3 
G
o
o
d
 
j
o
b
,
 
b
o
y
a
!


$ cat jerky 
Good job, boya!
*/