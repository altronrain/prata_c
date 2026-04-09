/* q10.c -- какие операторы допустимы

Имееются следующие объявления:

float rootbeer[10], things[10][5], *pf, value = 2.2;
int i = 3;

Какие из приведенных ниже операторов допустимы, а какие -- нет:

* rootbeer[2] = value;
* scanf ("%f", &rootbeer);
* rootbeer = value;
* printf ("%f", rootbeer);
* things[4][4] = rootbeer[3];
* things[5] = rootbeer;
* pf = value;
* pf = rootbeer;

*/
#include <stdio.h>

int main (void)
{
	float rootbeer[10], things[10][5], *pf, value = 2.2;
	int i = 3;	/* а зачем он тут вообще ??! */

	/* корректные объявления */
	rootbeer[2] = value;
	things[4][4] = rootbeer[3];	/* однако вопрос, rootbeer[3] не проинициализирован так то */
	pf = rootbeer;

	/* некорректные объявления */
	/* scanf ("%f", &rootbeer);	/* rootbeer уже указатель на начало массива. Если считываем один элемент */
	/* printf ("%f", rootbeer[0]);	/* то нужно добавить номер ячейки типа &rootbeer[2] */
					/* иначе передаем указатель на саму область памяти float (*)[10], что есть UB (но может и сработать) */
	/* rootbeer = value;		/* rootbeer указатель на начало массива, а value -- float */
	/* printf ("%f", rootbeer);	/* опять пытаемся вывести на печать несчастный указатель как float */
	/* things[5] = rootbeer;	/* присвоение массива в массив */
	/* pf = value;			/* присвоение указателю значения float */

	return 0;
}

/*
20:20 $ gcc q10.c -o q10 -Wall
q10.c: In function ‘main’:
q10.c:32:18: warning: format ‘%f’ expects argument of type ‘float *’, but argument 2 has type ‘float (*)[10]’ [-Wformat=]
   32 |         scanf ("%f", &rootbeer);
      |                 ~^   ~~~~~~~~~
      |                  |   |
      |                  |   float (*)[10]
      |                  float *

q10.c:35:18: error: assignment to expression with array type
   35 |         rootbeer = value;

q10.c:36:19: warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘float *’ [-Wformat=]
   36 |         printf ("%f", rootbeer);
      |                  ~^   ~~~~~~~~
      |                   |   |
      |                   |   float *
      |                   double

q10.c:37:19: error: assignment to expression with array type
   37 |         things[5] = rootbeer;

q10.c:38:14: error: incompatible types when assigning to type ‘float *’ from type ‘float’
   38 |         pf = value;
*/