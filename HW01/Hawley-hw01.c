/*James Hawley
01-20-2014
Homework#1*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*variables*/
	double Rnum, sum, average;
	int count1 = 0;
	/*loops*/
	int i,j;

	for(i = 0; i < 10; i = i + 1)/*ten rows*/
	{
		for(j = 0; j < 4; j = j + 1)/*four columbs*/
		{
			Rnum = rand() % 10000;/*range = [0,9999]*/
			Rnum = Rnum / 100.0;/*range now = [0,99.99]*/
			if(Rnum >= 67.0)
			{
				printf("%5.2f  ", Rnum);
				count1 = count1 + 1;
				sum = sum + Rnum;
			}
			else
			{
				printf("       ");
			}
		}
		if(sum == 0 && count1 == 0)/*divide by zero check*/
		{
			printf("|\n");
		}
		else
		{
			average = sum / count1;
			printf("|  %5.2f", average);
			printf("\n");
		}
		sum = 0;
		count1 = 0;
	}
}
