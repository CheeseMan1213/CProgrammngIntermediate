/*  put your function definitions in this file 

    any other libraries (e.g., stdio.h) needed by the functions in this file
    should be included
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw10-lib.h"


void f(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}
int GetData(FILE* data, struct Roster TheArray[])
{
	int k = 0, j = 0;
	char buffer[25];
	char temp[2][25];
	char* word;
	char* del = ",\n";

	while( (fgets(buffer, sizeof(buffer), data)) != NULL)
	{
		
		word = strtok(buffer, del);
		while(word != NULL)
		{
			strcpy(temp[j], word);
			j = j + 1;
			word = strtok(NULL, del);
		}

		j = 0;
		strcpy(TheArray[k].Name, temp[0]);
		strcpy(TheArray[k].Course, temp[1]);
		k = k + 1;
	}
	return k;
}
int GetNames(FILE* names, char TheArray[][16])
{
	int k = 0;
	char buffer[16];
	char* word;
	char* del = ",\n";
		
	while( (fgets(buffer, sizeof(buffer), names)) != NULL)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			strcpy(TheArray[k], buffer);
			k = k + 1;
			word = strtok(NULL, del);
		}
	}	
	return k;
}
void PrintData(struct Roster TheArray[], int size)
{
	int k;
	for(k = 0; k < size; k = k + 1)
	{
		printf("%s, %s\n", TheArray[k].Name, TheArray[k].Course);
	}
}
void PrintNames(char TheArray[][16], int size)
{
	int k;
	for(k = 0; k < size; k = k + 1)
	{
		printf("%s\n", TheArray[k]);
	}
}
void sort(struct Roster TheArray[], int size)
{
	int TRUE = 1, FALSE = 0;
	int Sorted = FALSE;
	int k, compair;
	struct Roster temp;

	while(Sorted == FALSE)
	{
		Sorted = TRUE;
		for(k = 0; k < size - 1; k = k + 1)
		{
			compair = strcmp(TheArray[k].Name, TheArray[k + 1].Name);
			if(compair >= 1)
			{
				temp = TheArray[k];
				TheArray[k] = TheArray[k + 1];
				TheArray[k + 1] = temp;
				Sorted = FALSE;
			}
		}
	}

}


int BinarySearch(struct Roster SortedArray[], int low, int high, char FindMe[16])
{
	int mid = ((high - low)/2) + low;
	int compair;
	
	if(low > high)
	{
		return -1;
	}

	compair = strcmp(SortedArray[mid].Name, FindMe);
	printf(".");

	if(compair == 0)
	{
		return mid;
	}
	else if(compair < 0)
	{
		return BinarySearch(SortedArray, (mid + 1), high, FindMe);
	}
	else if(compair > 0)
	{
		return BinarySearch(SortedArray, low, (mid - 1), FindMe);
	}
}

