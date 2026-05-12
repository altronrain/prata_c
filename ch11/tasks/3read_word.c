/* 3read_word.c  -- запись слова из потока ввода в массив

Разработайте и протестируйте функцию, которая читает первое слово из строки
ввода в массив и отбрасывает остальную часть строки. Функция должна пропускать
ведущие пробельные символы. Определите слово как последовательность символов,
не содержащую символов пробела, табуляции или новой строки.
Используйте функцию getchar(), а не scanf().
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 51

int getword (char str[], char *end);

int main (void)
{
	char word[SIZE];

	puts ("Input a string:");
	getword (word, word + SIZE);

	printf ("First word of the string: %s\n", word);

	return 0;
}

int getword (char str[], char *end)
{
	char *ptr;
	int ch;
	_Bool inword = 0;

	ptr = str;

	while ((ch = getchar()) != EOF) {

		if (!isspace(ch)) {		/* начало нового слова */
			inword = 1;
			if (ptr + 1 < end) {
				*ptr = ch;
				ptr++;
			}
			else {
				*ptr = '\0';
				return 1;
			}
		}

		if (isspace(ch) && inword) {	/* достигнут конец слова */
			inword = 0;
			*ptr = '\0';
			return 1;
		}
	}

	return 0;
}
/*
$ ./3read_word 
Input a string:
Sometimes it is better to think before taking an action
First word of the string: Sometimes

$ ./3read_word 
Input a string:
     oopsie SPACES
First word of the string: oopsie

$ ./3read_word 
Input a string:
striFirst word of the string: stri		<-- EOF

$ ./3read_word 
Input a string:
longstringlongstringlongstringlongstringlongstringlongstringlongstring yes
First word of the string: longstringlongstringlongstringlongstringlongstring
*/