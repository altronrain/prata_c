/* 9words.c  -- ввод и вывод слов

Напишите программу со следующим поведением.

* Сначала она запрашивает количество слов, которые нужно ввести.
* Затем она предлагает ввести слова
* После чего их отображает.

Воспользуйтесь malloc() и ответом на первый запрос (количество слов),
чтобы создать динамический массив с подходящим количеством указателей
на char. (Обратите внимание, что поскольку каждый элемент в массиве
является указателем на char, возвращаемое значение функции malloc()
должно сохраняться в указателе на указатель на char.)

При чтении строки программа должна читать слово во временный массив
элементов char, с помощью malloc() выделять пространство, достаточное
для хранения слова, и помещать адрес в массив указателей на char.

Далее программа должна копировать слово из временного массива в выделенное
пространство в памяти. Таким образом, в итоге получается массив указателей
на char, каждый из которых ссылается на объект с размером, необходимым для
хранения конкретного слова.

Результаты пробного запуска должны выглядеть следующим образом:

How many words do you like to enter? 5
Now enter 5 words:
I like this cool task
Here are the words you've entered:
I
like
this
cool
task
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void show_array (const char * const *ar, int n);

int main (void)
{
	int count;
	char **words;
	char buf[MAX_SIZE];
	int i;

	printf ("How many words do you like to enter? ");

	if (scanf ("%d", &count) != 1 || count <= 0) {
		printf ("Invalid number.\n");

		return 1;
	}

	words = malloc (count * sizeof(char *));
	if (!words) return 1;

	printf ("Now enter %d words:\n", count);

	for (i = 0; i < count; i++) {
		if (scanf ("%99s", buf) != 1) {
			count = i;
			break;
		}

		words[i] = malloc ((strlen (buf) + 1) * sizeof (char));
		strcpy (words[i], buf);
	}

	printf ("Here are the words you've entered:\n");
	show_array ((const char * const *)words, count);

	for (i = 0; i < count; i++)
		free (words[i]);

	free (words);

	return 0;
}

void show_array (const char * const *ar, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf ("%s\n", ar[i]);
}
/*
$ ./9words 
How many words do you like to enter? 5
Now enter 5 words:
i wanna be a star 
Here are the words you've entered:
i
wanna
be
a
star

$ ./9words 
How many words do you like to enter? 4
Now enter 4 words:
Luke you are a great jedi!
Here are the words you've entered:
Luke
you
are
a
*/