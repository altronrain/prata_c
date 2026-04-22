/* strings1.c  -- представление строк */
#include <stdio.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81

int main (void)
{
	char words[MAXLENGTH] = "I am a string, stored in array.";
	const char *pt1 = "Something points on me.";
	puts ("Here are multiple stings:");
	puts (MSG);
	puts (words);
	puts (pt1);
	words[7] = ' ';
	words[8] = ' ';
	puts (words);

	return 0;
}
/*
$ ./strings1 
Here are multiple stings:
I am a symbolic string constant.
I am a string, stored in array.
Something points on me.
I am a   ring, stored in array.
*/