/* James Hawley
02-02-2014
HW#2 */


#include <stdio.h>

int Divisorf(int n, int y);
int GetSum(int n );

int main(void)
{
	/*variables*/
	int a,b,count1 = 0, dcountA, dcountB, sum1 = 0;
	int maxCount = 0, ThatNumberWas;
	double average;
	/*loops*/
	int j; 
	
	printf("enter a positive integer: ");
	scanf("%d", &a);
	printf("enter a second, greater positive integer: ");
	scanf("%d", &b);
	printf("\n");

	dcountA = Divisorf(a, 0);/*those two new lines are printing because of
				these two function calls*/
	dcountB = Divisorf(b, 0);

	if(dcountA > dcountB)
	{
		printf("%d has more divisors than %d\n\n", a, b);
	}
	else if(dcountB > dcountA)
	{
		printf("%d has more divisors than %d\n\n", b, a);
	}
	else if(dcountA == dcountB)
	{
		printf("Both %d and %d have the same number of divisors\n\n", a,b);
	}

	maxCount = Divisorf(1, 0);
	
	for(j = a; j <= b; j = j + 1)
	{
		if(Divisorf(j, 0) > maxCount)
		{
			maxCount = Divisorf(j,0);
			ThatNumberWas = j;
		}
		printf("%2d:", j);
		count1 = count1 + Divisorf(j, 1);
		printf("\n");
		sum1 = sum1 + GetSum(j);
	}

	printf("\n");
	average = (double)sum1/count1;
	printf("the average number of divisors is %.2f\n", average);
	printf("%d has the most with %d divisors\n", ThatNumberWas, maxCount);
		
}
int Divisorf(int n, int y)
{
	/*variables*/
	int count = 0, sum = 0;
	/*loops*/
	int k;

	for(k = 1; k <= n; k = k + 1)
	{
		if(n%k == 0 && y == 1)
		{
			printf(" %d", k);
			count = count + 1;
			if(n != k)
			{
				printf(",");
			}
		}
		else if(n%k == 0 && y == 0)
		{
			count = count + 1;
		}
		
	}
	
	/**/
	
	return count;
			
}
int GetSum(int n)
{
	int q, sum = 0;

	for(q = 1; q <= n; q = q + 1)
	{
		if(n%q == 0)
		{
			sum = sum + q;
		}
	}

	return sum;
}
