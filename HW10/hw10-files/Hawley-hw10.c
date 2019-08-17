/*
    to compile, type
      make
*/
/*
James Hawley
20140413
HW10
*/

#include "hw10-lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp1, *fp2;
	struct Roster data[30];
	char names[10][16];
	int low = 0;
	int k, j, i, index;

	if( (fp1 = fopen("hw10-data.csv", "r")) == NULL)
	{
		printf("There was an error opening the file\n");
		exit(1);
	}

	k = GetData(fp1, data);
	fclose(fp1);
	sort(data, k);

	if( (fp2 = fopen("hw10-names.txt", "r")) == NULL)
	{
		printf("There was an error opening the file\n");
		exit(1);
	}
	
	i = GetNames(fp2, names);
	fclose(fp2);
	
	for(j = 0; j < i; j = j + 1)
	{
		printf("searching for %s", names[j]);
		index = BinarySearch(data, low, k, names[j]);
		if(index <= -1)
		{
			printf("not enrolled\n");
		}
		else
		{
			printf("enrolled in %s\n", data[index].Course);
		}
	}
	
}
