/*James Hawley
HW08
03-30-2014*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head(char** TheLines, int n, int nls);
void tail(char** TheLines, int n, int nls);
void both(char** TheLines, int n, int nls);
void sort(char** TheLines, int nls);
char* allocateTo1D(char* TheLinesj, int flag, int nls, int len);
char** allocateTo2D(char** TheLines, int x, int flag, int nls, int len);
void printall(char** TheLines, int nls);


int main(char argc, char* argv[50])
{
	char** TheLines;
	char buffer[1000];
	char* Line;
	char* del = "\n";
	int x = 4, j, nls = 0, len = 0;
	FILE* fp;
	char* temp1;
	char* temp2;
	
	/*argv[1] = the 'h' or 't' or 'b' or 's'*/
	int n = atoi(argv[2]);
	/*argv[3] =  FileName;*/
	

	TheLines = allocateTo2D(TheLines, x, 0, nls, len);
	for(j = 0; j < x; j = j + 1)
	{
		TheLines[j] = allocateTo1D(TheLines[j], 0, nls, len);
	}
	if( (fp = fopen(argv[3], "r")) == NULL)
	{
		printf("There was a problem with the file");
		exit(1);
	}
	while((fgets(buffer, sizeof(buffer), fp)) != NULL)
	{
		len = strlen(buffer) + 1;/*adding back on the newline and the terminating NULL*/
		TheLines[nls] = allocateTo1D(TheLines[nls], 1, nls, len);
		strcpy(TheLines[nls], buffer);
		nls = nls + 1;
		if(nls >= x)
		{
			x = x * 2;
			printf("reached limit...increasing potential strings to %d\n", x);
			TheLines = allocateTo2D(TheLines, x, 1, nls, len);
		}
		
		
	}
	if(*argv[1] == 'h')
	{
		head(TheLines, n, nls);
	}
	else if(*argv[1] == 't')
	{
		tail(TheLines, n, nls);
		
	}
	else if(*argv[1] == 'b')
	{
		both(TheLines, n, nls);
		
	}
	else if(*argv[1] == 's')
	{
		sort(TheLines, nls);
	}
	else
	{
		printf("Bad input");
		exit(1);
	}
	for(j = 0; j < nls; j = j + 1)
	{
		free(TheLines[j]);
	}
	free(TheLines);
}
void head(char** TheLines, int n, int nls)
{
	int k;
	
	if(n > nls)
	{
		for(k = 0; k < nls;k = k + 1)
		{
			printf("%s", TheLines[k]);	
		}
	}
	else
	{
		for(k = 0; k < n; k = k + 1)
		{
			printf("%s", TheLines[k]);
		}
	}
}
void tail(char** TheLines, int n, int nls)
{
	int k;
	
	if(n > nls)
	{
		for(k = 0; k < nls;k = k + 1)
		{
			printf("%s", TheLines[k]);	
		}
	}
	else
	{
		for(k = (nls - n); k < nls; k = k + 1)
		{
			printf("%s", TheLines[k]);
		}
	}
}
	
void both(char** TheLines, int n, int nls)
{
	
	int k;
	
	if(n >= nls || n >= nls/2)
	{
		for(k = 0; k < nls; k = k + 1)
		{
			printf("%s", TheLines[k]);		
		}
	}
	else
	{
		head(TheLines, n, nls);
		tail(TheLines, n, nls);
	}
}
void sort(char** TheLines, int nls)
{
	int FALSE = 0, TRUE = 1;
	int Sorted = FALSE;
	int j, compair;
	char* temp;

	while(Sorted == FALSE)
	{
		Sorted = TRUE;
		for(j = 0; j < nls - 1; j = j + 1)
		{
			compair = strcmp(TheLines[j], TheLines[j + 1]);
			if(compair >= 1)
			{
				temp = TheLines[j];
				TheLines[j] = TheLines[j + 1];
				TheLines[j + 1] = temp;
				Sorted = FALSE;
			}
		}
	}
	printall(TheLines, nls);
}
char* allocateTo1D(char* TheLinesj, int flag, int nls, int len)
{
	char* temp;
	
	if(flag == 0)
	{
		TheLinesj = malloc(5 * sizeof(char));
		return TheLinesj;
	}
	if(flag == 1)
	{
		temp = realloc(TheLinesj, len * sizeof(char));
		if(temp != NULL)
		{
			TheLinesj = temp;
		}
		else
		{
			printf("unable to reallocate");
			exit(1);
		}
		
		return TheLinesj;
	}
}
char** allocateTo2D(char** TheLines, int x, int flag, int nls, int len)
{
	char** temp1;
	char* temp2;
	int y, k = x;
	
	if(flag == 0)
	{
		TheLines = malloc(x * sizeof(char*));
		return TheLines;
	}
	if(flag == 1)
	{
		for(y = x/2; y < x; y = y + 1)
		{
			k = k + 1;
			temp1 = realloc(TheLines, k * sizeof(char*));
			if(temp1 != NULL)
			{
				TheLines = temp1;
			}
			else
			{
				printf("unable to reallocate");
				exit(1);
			}
			temp2 = malloc(5 * sizeof(char));
			if(temp2 != NULL)
			{
				TheLines[y] = temp2;
			}
			else
			{
				printf("unable to reallocate");
				exit(1);
			}
		}
		return TheLines;
	}
}
void printall(char** TheLines, int nls)
{
	int j;

	for(j = 0; j < nls; j = j + 1)
	{
		printf("%s", TheLines[j]);/*I am thinking that I already have the newlines from the file*/
	}
}
