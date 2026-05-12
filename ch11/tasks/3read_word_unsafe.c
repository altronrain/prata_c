/* 3read_word_unsafe.c  -- запись слова из потока ввода в массив

Разработайте и протестируйте функцию, которая читает первое слово из строки
ввода в массив и отбрасывает остальную часть строки. Функция должна пропускать
ведущие пробельные символы. Определите слово как последовательность символов,
не содержащую символов пробела, табуляции или новой строки.
Используйте функцию getchar(), а не scanf().
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 51

int getword (char str[]);

int main (void)
{
	char word[SIZE];

	puts ("Input a string:");
	getword (word);

	printf ("First word of the string: %s\n", word);

	return 0;
}

int getword (char str[])
{
	char *ptr;
	int ch;
	_Bool inword = 0;

	ptr = str;

	while ((ch = getchar()) != EOF) {

		if (!isspace(ch)) {		/* начало нового слова */
			inword = 1;
			*ptr = ch;
			ptr++;
		}

		if (isspace(ch) && inword) {	/* достигнут конец слова */
			inword = 0;
			*ptr = '\0';
			return 1;
		}
	}

	return 0;
}
/*
$ ./3read_word_unsafe 
Input a string:
Sometimes it is better to think before taking an action
First word of the string: Sometimes

$ ./3read_word_unsafe 
Input a string:
     oopsie SPACES
First word of the string: oopsie

$ ./3read_word_unsafe 
Input a string:
striFirst word of the string: stri		<-- EOF

gcc -Wall -fsanitize=address 3read_word_unsafe.c -o 3read_word_unsafe

22:16 $ ./3read_word_unsafe 
Input a string:
longstringlongstringlongstringlongstringlongstringlongstringlongstring yes
=================================================================
==25473==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7f193be00053 at pc 0x55787d4683d5 bp 0x7ffee0be0da0 sp 0x7ffee0be0d98
WRITE of size 1 at 0x7f193be00053 thread T0
    #0 0x55787d4683d4 in getword (/home/altron/Documents/repos/prata_c/ch11/tasks/3read_word_unsafe+0x13d4) (BuildId: e1bd39da107e88f21d472b8f0933943f25ea9078)
    #1 0x55787d468289 in main (/home/altron/Documents/repos/prata_c/ch11/tasks/3read_word_unsafe+0x1289) (BuildId: e1bd39da107e88f21d472b8f0933943f25ea9078)
    #2 0x7f193de35ca7 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x7f193de35d64 in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x55787d468120 in _start (/home/altron/Documents/repos/prata_c/ch11/tasks/3read_word_unsafe+0x1120) (BuildId: e1bd39da107e88f21d472b8f0933943f25ea9078)

Address 0x7f193be00053 is located in stack of thread T0 at offset 83 in frame
    #0 0x55787d4681f8 in main (/home/altron/Documents/repos/prata_c/ch11/tasks/3read_word_unsafe+0x11f8) (BuildId: e1bd39da107e88f21d472b8f0933943f25ea9078)

  This frame has 1 object(s):
    [32, 83) 'word' (line 17) <== Memory access at offset 83 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/home/altron/Documents/repos/prata_c/ch11/tasks/3read_word_unsafe+0x13d4) (BuildId: e1bd39da107e88f21d472b8f0933943f25ea9078) in getword
Shadow bytes around the buggy address:
  0x7f193bdffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193bdffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193bdffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193bdfff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193bdfff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x7f193be00000: f1 f1 f1 f1 00 00 00 00 00 00[03]f3 f3 f3 f3 f3
  0x7f193be00080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193be00100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193be00180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193be00200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f193be00280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==25473==ABORTING
*/