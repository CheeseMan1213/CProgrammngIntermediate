/*James Hawley
20140415
HW#11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11-lib.h"



int main(void)
{
	char* word;
	char* del = " \n";
	int i, j, k;
	char buffer[1000];
	struct node* root = NULL;
	int compair;

	while( (fgets(buffer, sizeof(buffer), stdin)) != NULL)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			if(root == NULL)
			{
				printf("add: %s\n", word);
				root = AddNode(word);
			}
			else
			{
				BinaryTree(root, word);
			}
			word = strtok(NULL, del);
		}
	}
	printf("\n");
	printf("RESULTS\n");	
	PrintTree(root);
	FreeMemory(root);
	
}
