/*James Hawley
HW03
02-09-2014*/

#include <stdio.h>

void longestWord(char a[], int counts[]);

int main(void)
{
	char S1[] = "This is one of Several strings2use.";
	char S2[] = "This sample has less than 987654321 leTTers.";
	char S3[] = "Is thIs a string?  (definitely)";
	char S4[] = "Twitter love its hashtags #twitterlove";
	char S5[] = "123 four five.";
	int counts[2] = {0,0}; /*initalized with zeros*/
	
	longestWord(S1,counts);
	printf("string  1: words = %2d, longest = %3d characters\n", counts[0], counts[1]);
	
	longestWord(S2,counts);
	printf("string  2: words = %2d, longest = %3d characters\n", counts[0], counts[1]);

	longestWord(S3,counts);
	printf("string  3: words = %2d, longest = %3d characters\n", counts[0], counts[1]);

	longestWord(S4,counts);
	printf("string  4: words = %2d, longest = %3d characters\n", counts[0], counts[1]);

	longestWord(S5,counts);
	printf("string  5: words = %2d, longest = %3d characters\n", counts[0], counts[1]);
		
			
			
}
void longestWord(char a[], int counts[])
{
	int WordCount = 0;
	int LongCount = 1;
	int b = 0;
	int CharCount = 0;

	while(a[b] != '\0')
	{
		if(!(('A' <= a[b] && a[b] <= 'Z') || ('a' <= a[b] && a[b] <= 'z')))
		{
			if(CharCount >= 1)
			{
				WordCount = WordCount + 1;
			}
			if(CharCount > LongCount)
			{
				LongCount = CharCount;
			}
			CharCount = 0;
		}
		else 
		{
			CharCount = CharCount + 1;
		}
		b = b + 1;
	}
	
	b = b - 1; /*returns to the final character in the array*/
	if((('A' <= a[b] && a[b] <= 'Z') || ('a' <= a[b] && a[b] <= 'z')))
	{
		WordCount = WordCount + 1;
		if(CharCount > LongCount)
		{
			LongCount = CharCount;
		}
	}
	
	counts[0] = WordCount;
	counts[1] = LongCount;
}
