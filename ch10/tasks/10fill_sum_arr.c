/* 10fill_sum_arr.c -- заполнение третьего массива поэлементной суммой двух массивов

Напишите функцию, которая устанавливает значение каждого элемента массива в сумму
соответствующих элементов в двух других массивах. Другими словами, если массив 1
имеет значения 2, 4, 5 и 8, а массив 2 -- значения 1, 0, 4 и 6, то эта функция
присваивает массиву 3 значения 3, 4, 9 и 14. Функция должна принимать в качетсве
аргументов имена трех массивов и их размеры. Протестируйте эту функцию с помощью
простой программы.
*/
#include <stdio.h>

void summ_arr (int [], int [], int [], int);
void print_arr(const int [], int, const char *);

int main (void)
{
	int source1[5] = {1, 4, 9, 3, 5};
	int source2[5] = {0, 7, 2, 8, 6};
	int target[5];


	summ_arr (target, source1, source2, 5);
	print_arr(target, 5, "target");

	return 0;
}

void summ_arr (int tgt[], int src1[], int src2[], int n)
{
	for (int i = 0; i < n; i++)
		tgt[i] = src1[i] + src2[i];
}

void print_arr(const int *arr, int n, const char *name)
{
	for (int i = 0; i < n; i++)
		printf("%s[%d] = %d\n", name, i, arr[i]);

	printf("\n");
}
/*
$ ./10fill_sum_arr 
target[0] = 1
target[1] = 11
target[2] = 11
target[3] = 11
target[4] = 11

*/