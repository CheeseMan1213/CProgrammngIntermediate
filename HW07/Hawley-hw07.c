/*James Hawley
HW07
03-13-2014*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE* newfile;
	char** TheWords;
	char buffer[100];
	char temp[12];
	char* word;
	char* del = ",\n";
	int compair;
	int i, j, count = 0, len1, len2;
	int TRUE = 1, FALSE = 0, Sorted;
	Sorted = FALSE;
	
	TheWords = malloc(50 * sizeof(char*));

	for(i = 0; i < 50; i = i + 1)
	{
		TheWords[i] = malloc(12 * sizeof(char));
	}

	if( (newfile = fopen("hw07-data.csv", "r")) == NULL)
	{
		printf("There was an error.\n");
		exit(1);
	}
	
	i = 0;
	while( (fgets(buffer, sizeof(buffer), newfile)) != NULL)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			strcpy(TheWords[i], word);
			i = i + 1;
			word = strtok(NULL, del);
		}
	}

	for(j = 0; j < i; j = j + 1)
	{
		printf("%-12s", TheWords[j]);
		count = count + 1;
		if(count >= 5)
		{
			printf("\n");
			count = 0;
		}
	}
	printf("\n");
	

	while(Sorted == FALSE)
	{
		Sorted = TRUE;
		for(j = 0; j < i - 5; j = j + 1)
		{
			len1 = strlen(TheWords[j]);
			len2 = strlen(TheWords[j + 5]);
			if(len1 > len2)
			{
				strcpy(temp, TheWords[j]);
				strcpy(TheWords[j], TheWords[j + 5]);
				strcpy(TheWords[j + 5], temp);
				Sorted = FALSE;
			}
			else if(len1 == len2)
			{
				compair = strcmp(TheWords[j], TheWords[j + 5]);
				if(compair >= 1)
				{
					strcpy(temp, TheWords[j]);
					strcpy(TheWords[j], TheWords[j + 5]);
					strcpy(TheWords[j + 5], temp);
					Sorted = FALSE;
				}
			}
					
		}
	}
		
	

	for(j = 0; j < i; j = j + 1)
	{
		printf("%-12s", TheWords[j]);
		count = count + 1;
		if(count >= 5)
		{
			printf("\n");
			count = 0;
		}	
	}

	for(i = 0; i < 50; i = i + 1)
	{
		free(TheWords[i]);
	}

	free(TheWords);
	
}
