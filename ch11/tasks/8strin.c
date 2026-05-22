/* 8strin.c -- вхождение строк

Напишите функцию string_in(), которая принимает в качестве аргументов
два указателя на строки. Если вторая строка содержится внутри первой,
функция должна возвратить адрес, с которого начинается вторая строка
в первой строке.
Например, вызов string_in("dataset", "as") возвратит адрес второго символа
'a' в строке "dataset".
Протестируйте функцию в завершенной программе, которая использует цикл
для передачи входных значений созданной функции.
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80

char * s_gets (char *st, int n);
char * string_in (const char *tgt, const char *data);
char * string_in2 (const char *tgt, const char *data);

int main (void)
{
	char str1[SIZE];
	char str2[SIZE];
	char *ptr;

	puts ("Введите строку (или пустую строку для выхода из программы):");

	while (s_gets (str1, SIZE) && str1[0] != '\0') {

		puts ("Введите подстроку (или пустую строку для выхода из программы):");
		if (s_gets (str2, SIZE) == NULL || str2[0] == '\0') {
			break;
		}

		ptr = string_in2 (str1, str2);

		if (ptr) {
			printf ("Получен следующий адрес: %p, это %ld буква строки\n",
				ptr, ptr - str1 + 1);
		}
		else {
			puts ("Такая подстрока отсутствует в переданной строке");
		}

		puts ("Введите новую строку (или пустую строку для выхода из программы): ");
	}

	puts ("Готово.");

	return 0;
}

char * s_gets (char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets (st, n, stdin);

	if (ret_val) {	/* или просто ret_val, но не рекомендуется */
		while (st[i] != '\n' && st[i] != '\0')
			i++;

		if (st[i] == '\n')
			st[i] = '\0';
		else	/* requires words[i] == '\0' */
			while (getchar () != '\n')
				;
	}

	return ret_val;
}

char * string_in (const char *src, const char *data)
{
	const char *ptr1, *ptr2;
	const char *res = NULL;
	_Bool inword = 0;

	ptr1 = src;
	ptr2 = data;

	while (*ptr1 != '\0' && *ptr2 != '\0') {
		if (*ptr1 != *ptr2) {
			res = NULL;
			inword = 0;
			ptr2 = data;
		}
		else if (*ptr1 == *ptr2 && inword == 0) {
			inword = 1;
			res = ptr1;
			ptr2++;
		}
		else if (*ptr1 == *ptr2 && inword) {
			ptr2++;
		}

		ptr1++;
	}

	return res;
}

char * string_in_ai (const char *src, const char *data)
{
	const char *p1 = src;

	while (*p1 != '\0') {
		const char *m1 = p1;
		const char *m2 = data;

		/* Внутренний цикл проверяет совпадение посимвольно */
		while (*m1 != '\0' && *m2 != '\0' && *m1 == *m2) {
			m1++; m2++;
		}

		if (*m2 == '\0') return p1; /* Подстрока полностью совпала */

		p1++; /* Сдвигаем начало поиска в основной строке */
	}

	return NULL;
}

char * string_in2 (const char *src, const char *data)
{
	const char *ptr = src;
	const size_t len = strlen (data);

	while (*ptr) {
		if (strncmp (ptr, data, len) == 0) {
			return ptr;
		}

		ptr++;
	}

	return NULL;
}
/*
$ ./8strin
Введите строку (или пустую строку для выхода из программы):
dataset
Введите подстроку (или пустую строку для выхода из программы):
as
Получен следующий адрес: 0x7ffeecb51343, это 4 буква строки
Введите новую строку (или пустую строку для выхода из программы): 
script
Введите подстроку (или пустую строку для выхода из программы):
scar
Такая подстрока отсутствует в переданной строке
Введите новую строку (или пустую строку для выхода из программы): 
blight
Введите подстроку (или пустую строку для выхода из программы):
light
Получен следующий адрес: 0x7ffeecb51341, это 2 буква строки
Введите новую строку (или пустую строку для выхода из программы): 

Готово.

(string_in2)
$ ./8strin2 
Введите строку (или пустую строку для выхода из программы):
dataset 
Введите подстроку (или пустую строку для выхода из программы):
as
Получен следующий адрес: 0x7ffc4a57be33, это 4 буква строки
Введите новую строку (или пустую строку для выхода из программы): 
feature
Введите подстроку (или пустую строку для выхода из программы):
eat
Получен следующий адрес: 0x7ffc4a57be31, это 2 буква строки
Введите новую строку (или пустую строку для выхода из программы): 

Готово.
*/