#include <stdio.h>

int main(void)
{
	char q[5] = "World";
	int b;
	
	printf("Hello %s\n", q);
	printf("Please enter an integer: ");
	scanf("%d", &b);
	printf("You entered %d\n", b);
	printf("Please type a word: ");
	scanf("%s", q);
	printf("The word you typed was %s\n", q);
	printf("All done.\n");

}
/*
mistakes made:
-there is no string datatype in C
for now you know how to create an array of
characters
-you must declare a string with 'char'
-put semi colon at end of mostly all lines
-don't forget to put a newline at the end of your
code too.  Otherwise when the program finishes
your terminal prompt will come back into use
on the same(last) line of the code you just ran. or it just won't print at all
*/