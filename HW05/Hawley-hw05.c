/**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CollectData(FILE* file, double* avg, double* SmpVar, int* min, int* max);

int main(void)
{
	FILE* newfile;
	double avg, SmpVar;
	int min, max;
	double* ptravg = &avg;
	double* ptrSmpVar = &SmpVar;
	int* ptrmin = &min;
	int* ptrmax = &max;

	if( (newfile = fopen("hw05-data-1.txt", "r")) == NULL )
	{
		printf("There was an error.\n");
		exit(1);
	}

	CollectData(newfile, ptravg, ptrSmpVar, ptrmin, ptrmax);
	printf("the max was %d.\n", max);
	printf("the min was %d.\n", min);
	printf("the average was %f.\n", avg);
	printf("the Sample Varience was %f.\n", SmpVar);

	fclose(newfile);
	
	
	/*
	
	char buffer[50];
	char* word;
	char* del = " ";
	int k = 0, j = 1, WordLen, num = 0;
	int sum1 = 0, sum2 = 0, count = 0;
	int cycle = 0;
	double avg;
	if( (newfile = fopen("hw05-data-1.txt", "r")) == NULL )
	{
		printf("There was an error.\n");
		exit(1);
	}

	while( (fgets(buffer, sizeof(buffer), newfile)) != NULL )
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			if(word[0] == '$')
			{
				num = atoi(&word[1]);
				sum1 = sum1 + num;
				count = count + 1;
			}
			word = strtok(NULL, del);
		}
	}
	avg = (double)sum1/count;
	printf("The average is %.2lf\n", avg);
	
	fclose(newfile);
	*/
}
void CollectData(FILE* file, double* avg, double* SmpVar, int* min, int* max)
{
	char buffer1[50], buffer2[50];
	int numbers[50] = {0,0,0};
	int cycle = 0;
	char* word;
	char* del = " ";
	int k = 0, j = 1, num = 0;
	int sum1 = 0, count = 0, count2 = 0;
	double A = 0, S = 0, mid = 0, sum2 = 0;
	int MIN = 0, MAX = 0;
	

	while( (fgets(buffer1, sizeof(buffer1), file)) != NULL )
	{
		word = strtok(buffer1, del);
		while(word != NULL)
		{
			if(word[0] == '$')
			{
				num = atoi(&word[1]);
				printf("%d*\n", num);
				if (count2 == 0)
				{
					MAX = num;
					MIN = num;
					count2 = count2 + 1;
				}
				if(num > MAX)
				{
					MAX = num;
				}
				if(num < MIN)
				{
					MIN = num;
				}
				sum1 = sum1 + num;
				count = count + 1;
			}
			while(cycle < 50)
			{
				numbers[cycle] = num;
				cycle = cycle + 1;
			}
			word = strtok(NULL, del);
		}
	}
	A = (double)sum1/count;
	printf("Here*\n");
	k = 0;
	/*
	while(k < 50)
	{
		if(numbers[k] != 0)
		{
			printf("%d^\n", numbers[k]);
		}
		k = k + 1;
	}
	*/
	k = 0;
	while(k < 50)
	{
		mid = numbers[k] - A;
		mid = mid * mid;
		sum2 = sum2 + mid;
		k = k + 1;
	}
	count = count - 1;
	S = sum2/count;
	*avg = A;
	*min = MIN;
	*max = MAX;
	*SmpVar = S;
	
}

