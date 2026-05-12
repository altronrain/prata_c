/* 4read_word_or_n.c  -- запись слова из потока ввода в массив

Разработайте и протестируйте функцию, подобну описанной в упражнении 3,
за исключением того, что она принимает второй параметр, указывающий максимальное
колличество символов, которые могут быть прочитаны.
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 51
#define LIMIT 10

int getword (char str[], int n);

int main (void)
{
	char word[SIZE];

	puts ("Input a string:");
	getword (word, LIMIT);

	printf ("First word of the string: %s\n", word);

	return 0;
}

int getword (char str[], int n)
{
	char *ptr;
	int ch;
	int i = 0;
	_Bool inword = 0;

	ptr = str;

	while ((ch = getchar()) != EOF && i < n) {

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

		i++;
	}

	return 0;
}
/*
$ ./4read_word_or_n
Input a string:
Sometimes it is better to think before taking an action
First word of the string: Sometimes

$ ./4read_word_or_n
Input a string:
     oopsie SPACES
First word of the string: oopsi

22:37 $ ./4read_word_or_n
Input a string:
striFirst word of the string: stri		<-- EOF

gcc -Wall -fsanitize=address 3read_word_unsafe.c -o 3read_word_unsafe

$ ./4read_word_or_n
Input a string:
longstringlongstringlongstringlongstringlongstringlongstringlongstring yes
First word of the string: longstring

LIMIT = 100					<-- В целом это уже ССЗБ

$ ./4read_word_or_n
Input a string:
longstringlongstringlongstringlongstringlongstringlongstringlongstring yes
=================================================================
==29600==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7f6d90600053 at pc 0x556bb6daf3e4 bp 0x7ffcbcf08f60 sp 0x7ffcbcf08f58
WRITE of size 1 at 0x7f6d90600053 thread T0
    #0 0x556bb6daf3e3 in getword (/home/altron/Documents/repos/prata_c/ch11/tasks/4read_word_or_n_unsafe+0x13e3) (BuildId: fc172443593d8485b8859259e22d8d574fb57143)
    #1 0x556bb6daf28e in main (/home/altron/Documents/repos/prata_c/ch11/tasks/4read_word_or_n_unsafe+0x128e) (BuildId: fc172443593d8485b8859259e22d8d574fb57143)
    #2 0x7f6d92635ca7 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x7f6d92635d64 in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x556bb6daf120 in _start (/home/altron/Documents/repos/prata_c/ch11/tasks/4read_word_or_n_unsafe+0x1120) (BuildId: fc172443593d8485b8859259e22d8d574fb57143)

Address 0x7f6d90600053 is located in stack of thread T0 at offset 83 in frame
    #0 0x556bb6daf1f8 in main (/home/altron/Documents/repos/prata_c/ch11/tasks/4read_word_or_n_unsafe+0x11f8) (BuildId: fc172443593d8485b8859259e22d8d574fb57143)

  This frame has 1 object(s):
    [32, 83) 'word' (line 16) <== Memory access at offset 83 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/home/altron/Documents/repos/prata_c/ch11/tasks/4read_word_or_n_unsafe+0x13e3) (BuildId: fc172443593d8485b8859259e22d8d574fb57143) in getword
Shadow bytes around the buggy address:
  0x7f6d905ffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d905ffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d905ffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d905fff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d905fff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x7f6d90600000: f1 f1 f1 f1 00 00 00 00 00 00[03]f3 f3 f3 f3 f3
  0x7f6d90600080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d90600100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d90600180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d90600200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f6d90600280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
==29600==ABORTING
*/