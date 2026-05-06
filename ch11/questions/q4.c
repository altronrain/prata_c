/* q4.c  -- что выведет программа */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char goldwyn[40]   = "ad a part of it ";	/* 16 + 1 */
	char samuel[40]    = "I re";			/* 4 + 1 */
	const char * quote = "all the way through.";	/* 20 + 1 */

	strcat (goldwyn, quote);	/* (37) goldwyn = "ad a part of it all the way through." */
	strcat (samuel, goldwyn);	/* (41)? samuel = "I read a part of it all the way through." */
	puts (samuel);			/* UB */

	return 0;
}
/*
$ ./q4
I read a part of it all the way through.

$ gcc -fsanitize=address -g q4.c -o q4_2

$ ./q4_2
=================================================================
==7812==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7f9d12700098 at pc 0x7f9d14aedb56 bp 0x7fff0a971680 sp 0x7fff0a970e40
WRITE of size 37 at 0x7f9d12700098 thread T0
    #0 0x7f9d14aedb55 in strcat ../../../../src/libsanitizer/asan/asan_interceptors.cpp:515
    #1 0x55ff1a7c13b8 in main /home/altron/Documents/repos/prata_c/ch11/questions/q4.c:12
    #2 0x7f9d14835ca7 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x7f9d14835d64 in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x55ff1a7c10e0 in _start (/home/altron/Documents/repos/prata_c/ch11/questions/q4_2+0x10e0) (BuildId: 1337394b00f95b737c209400d8fe3775fc07130d)

Address 0x7f9d12700098 is located in stack of thread T0 at offset 152 in frame
    #0 0x55ff1a7c11b8 in main /home/altron/Documents/repos/prata_c/ch11/questions/q4.c:6

  This frame has 2 object(s):
    [32, 72) 'goldwyn' (line 7)
    [112, 152) 'samuel' (line 8) <== Memory access at offset 152 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow ../../../../src/libsanitizer/asan/asan_interceptors.cpp:515 in strcat
Shadow bytes around the buggy address:
  0x7f9d126ffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d126ffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d126fff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d126fff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d12700000: f1 f1 f1 f1 00 00 00 00 00 f2 f2 f2 f2 f2 00 00
=>0x7f9d12700080: 00 00 00[f3]f3 f3 f3 f3 00 00 00 00 00 00 00 00
  0x7f9d12700100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d12700180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d12700200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d12700280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f9d12700300: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
==7812==ABORTING

*/