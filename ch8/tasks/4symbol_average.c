/* 4symbol_average.c -- Подсчет среднего количества букв в словах

Напишите программу, которая читает ввод как поток символов, пока не встретит EOF.
Программа должна сообщать среднее количество букв в словах.
Не считайте пробельные символы в словах буквами. На самом деле, также не должны
учитываться и знаки препинания, но в данном упражнении об этом можно не беспокоиться.

(Для учета знаков препинания можно воспользоваться функцией ispunct() из семейства
ctype.h)
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int wc = 0, cc = 0;
	_Bool in_word = 0;

	while ((ch = getchar ()) != EOF)
	{
		if (!isspace(ch) && !ispunct(ch))
			cc++;
		if (!isspace(ch) && !in_word)
		{
			in_word = 1;
			wc++;
		}
		if (isspace(ch) && in_word)
			in_word = 0;
	}

	printf ("\n");
	printf ("Букв в потоке ввода: %d\nСлов в потоке ввода:%d\n", cc, wc);
	printf ("Среднее количество букв в слове: %.2f\n", (float) cc / wc);

	return 0;
}

/*
$ ./4symbol_average 
Luke, use your power wisely!

Букв в потоке ввода: 22
Слов в потоке ввода:5
Среднее количество букв в слове: 4.40

$ cat test.txt 
This is a test string.
$ ./4symbol_average <test.txt 

Букв в потоке ввода: 17
Слов в потоке ввода:5
Среднее количество букв в слове: 3.40
*/