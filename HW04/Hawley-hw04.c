/*James Hawley
HW04
02-18-2014*/

#include <stdio.h>

void FindMax(int num[][5], int rows, int* colIndex, int* maxSum);
void FindAvgAndVarc(int num[][5], int rows, int colIndex, double* mean, double* var);
int main(void)
{
	int size, Index, maxSum;
	double mean, var;
	int* ptrIndex = &Index;
	int* ptrmaxSum = &maxSum;
	double* ptrmean = &mean;
	double* ptrvar = &var;

	int A1[][5] = {{ 55, 8, 12,  6, -1},
		       {-10, 4,  7,  5, -6},
		       {-20, 0, 15,  4, -2}};


	int A2[][5] = {{1, 6, -2,  5, 14},
		       {0, 4,  3, -5, 12},
		       {2, 4,  5, -6, 12},
		       {4, 7, 15,  4, 16},
		       {3, 9,  4,  0, 17}};
	
	size = sizeof(A1)/sizeof(A1[0]);
	FindMax(A1, size, ptrIndex, ptrmaxSum);
	FindAvgAndVarc(A1, size, Index, ptrmean, ptrvar);
	printf("For the first array, the column with index %d has the maximum sum of %d\n", Index, maxSum);
	printf("It has a mean of %.3f and a variance of %.3f\n\n", mean, var);
	
	
	size = sizeof(A2)/sizeof(A2[0]);
	FindMax(A2, size, ptrIndex, ptrmaxSum);
	FindAvgAndVarc(A2, size, Index, ptrmean, ptrvar);
	printf("For the second array, the column with index %d has the maximum sum of %d\n", Index, maxSum);
	printf("It has a mean of %.3f and a variance of %.3f\n", mean, var);
}
void FindMax(int num[][5], int rows, int* colIndex, int* maxSum)
{
	int j, k;
	int TheMax = 0, runMax = 0;
	int Index = 0;

	for(k = 0; k < 5; k = k + 1)
	{
		for(j = 0; j < rows; j = j + 1)
		{
			runMax = runMax + num[j][k];
		}
		if(runMax > TheMax)
		{
			TheMax = runMax;
			Index = k;
		}
		runMax = 0;
	}
	*colIndex = Index;
	*maxSum = TheMax;
}

void FindAvgAndVarc(int num[][5], int rows, int colIndex, double* mean, double* var)
{
	int sum = 0, count = 0;
	int q;
	double avg, varc, mid, sum1 = 0.0;

	for(q = 0; q < rows; q = q + 1)
	{
		sum = sum + num[q][colIndex];	
		count = count + 1;
	}
	avg = sum/(double)count;
	sum = 0;
	count = 0;

	for(q = 0; q < rows; q = q + 1)
	{
		mid = sum + (num[q][colIndex] - avg);
		mid = mid * mid;
		sum1 = sum1 + mid;
		count = count + 1;
	}
	count = count - 1;
	varc = sum1/count;

	*mean = avg;
	*var = varc;
}
