/* wordcnt.c -- подсчет символов, слов, строк */
#include <stdio.h>
#include <ctype.h>
#define STOP '|'

int main(void)
{
	char c;
	char prev = '\n';						/* используется для идентификации неполных строк */
											/* инициализируем так как можем попасть в условие минуя присвоение */
	long n_chars = 0L;						/* счетчик символов (L для наглядности) */
	int n_words = 0;						/* счетчик слов */
	int n_lines = 0;						/* счетчик строк */
	int p_lines = 0;						/* счетчик неполных строк */
	_Bool inword = 0;						/* флаг нахождения слова */

	printf("Введите текст для анализа (символ | для завершения):\n");

	while ((c = getchar ()) != STOP) {
		n_chars++;							/* считать символы */
		if (c == '\n')
			n_lines++;						/* считать строки */
		if (!isspace(c) && !inword) {
			inword = 1;						/* начало нового слова */
			n_words++;						/* считать слова */
		}
		if (isspace(c) && inword)
			inword = 0;						/* достигнут конец слова */

		prev = c;
	}

	if (prev != '\n')
		p_lines = 1;

	printf ("символов = %ld, слов = %ld, строк = %ld, ",
			n_chars, n_words, n_lines);
	printf ("неполных строк = %d\n", p_lines);

	return 0;
}

/*
$ ./wordcnt
Введите текст для анализа (символ | для завершения):
The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep.
|
символов = 98, слов = 20, строк = 3, неполных строк = 0

$ ./wordcnt 
Введите текст для анализа (символ | для завершения):
Mr.Anderson, are you ready?|
символов = 27, слов = 4, строк = 0, неполных строк = 1
*/