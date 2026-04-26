/* puts.c  -- использование функции puts() */
#include <stdio.h>
#define DEF "I am the string, defined by #define directive."

int main (void)
{
	char str1[80] = "An array was initialized with my value.";
	const char * str2 = "A pointer was initialized with my value.";

	puts ("I am an argument of the puts() function.");
	puts (DEF);
	puts (str1);
	puts (str2);
	puts (&str1[5]);
	puts (str2 + 4);

	return 0;
}
/*
$ ./puts 
I am an argument of the puts() function.
I am the string, defined by #define directive.
An array was initialized with my value.
A pointer was initialized with my value.
ray was initialized with my value.
inter was initialized with my value.
*/