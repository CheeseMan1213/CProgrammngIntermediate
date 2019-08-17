/*
    to compile, type
      make
*/
/*
James Hawley
20140413
HW10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Roster
{
	char Name[16];
	char Coarse[10];
};

int GetData(FILE* data, char TheArray[][30]);

int main(void)
{
	FILE* fp1, *fp2;
	char TheData[50][30];
	char TheNames[10][30];
	struct Roster Testt[25];
	char* data;
	char* names;
	int k, i;
	if( (fp1 = fopen("hw10-data.csv", "r")) == NULL)
	{
		printf("There was an error opening the file\n");
		exit(1);
	}
	i = GetData(fp1, TheData);
	fclose(fp1);
	
	for(k = 0; k < i; k = k + 1)
	{
		printf("%s\n", TheData[k]);
	}
	printf("\n");
	
	if( (fp2 = fopen("hw10-names.txt", "r")) == NULL)
	{
		printf("There was an error opening the file\n");
		exit(1);
	}
	
	i = GetData(fp2, TheNames);
	
	fclose(fp2);
	for(k = 0; k < i; k = k + 1)
	{
		printf("%s\n", TheNames[k]);
	}
	
}
int GetData(FILE* data, char TheArray[][30])
{
	char buffer[30];
	char* word;
	char* del = ",\n";
	int k = 0;
	
	while( fgets(buffer,sizeof(buffer), data) != NULL)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			strcpy(TheArray[k], word);
			k = k + 1;
			word = strtok(NULL, del);
		}
	}
	return k;
	
}
