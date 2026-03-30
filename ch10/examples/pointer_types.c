/* pointer_types.c  -- типы указателей */
#include <stdio.h>

int main (void)
{
	int *pt;
	int (*pa)[3];
	int arr1[2][3];
	int arr2[3][2];
	int **p2;

	pt = &arr1[0][0]; /* допустимо, оба -- указатели на int */
	pa = &arr1[0];    /* допустимо, оба -- указатели на int (*)[3] */
	pt = arr1;        /* недопустимо arr1 -- массив массивов int (*)[3] */
	pa = arr1;        /* допустимо, оба -- указатели на int (*)[3] */
	pa = arr2;        /* недопустимо, arr2 -- массив массивов int (*)[2] */
	p2 = &pt;         /* допустимо, оба -- указатели на int ** */
	*p2 = arr2[0];    /* допустимо, оба -- указатели на int */
	p2 = arr2;        /* недопустимо, arr2 -- массив массивов int (*)[2] */
}

/*
19:24 $ gcc pointer_types.c -o pointer_types
pointer_types.c: In function ‘main’:
pointer_types.c:14:12: error: assignment to ‘int *’ from incompatible pointer type ‘int (*)[3]’ [-Wincompatible-pointer-types]
   14 |         pt = arr1;
      |            ^
pointer_types.c:16:12: error: assignment to ‘int (*)[3]’ from incompatible pointer type ‘int (*)[2]’ [-Wincompatible-pointer-types]
   16 |         pa = arr2;
      |            ^
pointer_types.c:19:12: error: assignment to ‘int **’ from incompatible pointer type ‘int (*)[2]’ [-Wincompatible-pointer-types]
   19 |         p2 = arr2;
*/