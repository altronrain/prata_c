/* q12.c -- написать прототипы и операторы вызова функций

Имееются следующие объявления массивов:

double trots[20];
short clops[10][30];
long shots[5][10][15];

* Напишите прототип и оператор вызова для традиционной функции типа void,
которая обрабатывает массив trots, и для функции C, использующей массив
переменной длины
* Напишите прототип и оператор вызова для традиционной функции типа void,
которая обрабатывает массив clops, и для функции C, использующей массив
переменной длины
* Напишите прототип и оператор вызова для традиционной функции типа void,
которая обрабатывает массив shots, и для функции C, использующей массив
переменной длины

*/
void process_trots (int [], int);
void process_1d (int, int arr[*]);

void process_clops (int [][30], int);
void process_2d (int rows, int cols, int arr[rows][cols]);

/* void process_shots (int (*arr)[10][15], int rows); -- эквивалент */
void process_shots (int arr[][10][15], int);
void process_3d (int, int, int, int arr[*][*][*]);

int main (void)
{
	double trots[20];
	short clops[10][30];
	long shots[5][10][15];

	return 0;
}

void process_trots (int arr[], int rows)
{
	return;
}

void process_1d (int rows, int arr[rows])
{
	return;
}

void process_clops (int [][30], int rows)
{
	return;
}

void process_2d (int rows, int cols, int arr[rows][cols])
{
	return;
}

void process_shots (int arr[][10][15], int rows)
{
	return;
}

void process_3d (int x, int y, int z, int arr[x][y][z])
{
	return;
}

/*	unused var тут нормально
$ gcc q12.c -o q12 -Wall
q12.c: In function ‘main’:
q12.c:36:14: warning: unused variable ‘shots’ [-Wunused-variable]
   36 |         long shots[5][10][15];
      |              ^~~~~
q12.c:35:15: warning: unused variable ‘clops’ [-Wunused-variable]
   35 |         short clops[10][30];
      |               ^~~~~
q12.c:34:16: warning: unused variable ‘trots’ [-Wunused-variable]
   34 |         double trots[20];
      |                ^~~~~
*/