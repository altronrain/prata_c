/* arrchar.c  -- массив указателей и массив строк */
#include <stdio.h>
#define SLEN 40
#define LIM 5

int main (void)
{
	/* массив из 5 указателей, занимающий 40 байтов */
	/* возможны литералы различных длин. Удобное хранение для вызова строк для отображения */
	const char *mytalents[LIM] = {
		"Instant addition of numbers",
		"Exact multiplication", "Data accumulation",
		"Precise execution of insructions",
		"Knowledge of C programming language"
	};
	/* массив из пяти массивов по 40 значений char, занимающий 200 байтов */
	/* такой вариант неудобен, ибо требует не превышеть SLEN для каждого из элементов */
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Healthy sleep", "Watching TV",
		"Sending emails", "Reading emails"
	};

	puts ("Let's compare our talents.");
	printf ("%-52s %-25s\n", "My talents", "Your talents");

	for (int i = 0; i < LIM; i++)
		printf ("%-52s %-25s\n", mytalents[i], yourtalents[i]);

	printf ("\nsize mytalents: %zd, size yourtalents: %zd\n",
		sizeof mytalents, sizeof yourtalents);

	return 0;
}
/*
$ ./arrchar 
Let's compare our talents.
My talents                                           Your talents             
Instant addition of numbers                          Walking in a straight line
Exact multiplication                                 Healthy sleep            
Data accumulation                                    Watching TV              
Precise execution of insructions                     Sending emails           
Knowledge of C programming language                  Reading emails           

size mytalents: 40, size yourtalents: 200
*/