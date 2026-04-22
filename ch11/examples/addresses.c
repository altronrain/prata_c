/* addresses.c  -- адреса строк */
#include <stdio.h>
#define MSG "I am special."

int main (void)
{
	char ar[] = MSG;
	const char *pt = MSG;

	printf ("адрес фразы \"I am special.\": %p\n", "Я особенный.");
	printf ("                   адрес ar: %p\n", ar);
	printf ("                   адрес pt: %p\n", pt);
	printf ("                  адрес MSG: %p\n", MSG);
	printf ("адрес фразы \"I am special.\": %p\n", "Я особенный.");

	return 0;
}
/*
$ ./addresses 
адрес фразы "I am special.": 0x560da0662016  <- литерал в неизменяемой области памяти
                   адрес ar: 0x7ffdc3424d1a  <- массив в изменяемой области памяти
                   адрес pt: 0x560da0662008  <- указатель на литерал в неизменяемой области памяти pt == MSG
                  адрес MSG: 0x560da0662008  <- другой литерал в неизменяемой области памяти
адрес фразы "I am special.": 0x560da0662016  <- тот же литерал в неизменяемой области памяти что и первый (но это зависит от компилятора)
*/