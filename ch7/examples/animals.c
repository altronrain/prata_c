/* animals.c -- использование оператора switch */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;						/* для кириллицы char не подойдет и будут warining'и */

	printf ("Give me a letter and I'll tell you ");
	printf ("an animal,\nwhose name starts with this letter.\n");
	printf ("Enter a letter or # to end input.\n");
	while ((ch = getchar()) != '#') {
		if ('\n' == ch)
			continue;
		if (islower (ch))
			switch (ch) {
			case 'a' :
				printf ("albatross, seagull species\n");
				break;
			case 'b' :
				printf ("bobcat, wild cat-like creature\n");
				break;
			case 'c' :
				printf ("coyote, canine species\n");
				break;
			case 'd' :
				printf ("deer, has a tasty meat\n");
				break;
			case 'm' :
				printf ("mongoose, fights snakes furiously\n");
				break;
			case 'p' :
				printf ("pangolin, have large, protective keratin scales\n");
				break;
			default:
				printf ("I'm out of ideas!\n");
			}
		else
			printf ("Please, use lower case.\n");
		while (getchar() != '\n')
			continue;
		printf ("Enter next letter or # to end input.\n");
	}

	printf ("End of program.\n");

	return 0;
}

/*
$ ./animals 
Give me a letter and I'll tell you an animal,
whose name starts with this letter.
Enter a letter or # to end input.
a
albatross, seagull species
Enter next letter or # to end input.
p
pangolin, have large, protective keratin scales
Enter next letter or # to end input.
t
I'm out of ideas!
Enter next letter or # to end input.
A
Please, use lower case.
Enter next letter or # to end input.
#
End of program.
*/