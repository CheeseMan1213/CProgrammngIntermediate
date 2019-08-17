/*  put your function definitions in this file 

    any other libraries (e.g., stdio.h) needed by the functions in this file
    should be included
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11-lib.h"

struct node* AddNode(char* Name)
{
	struct node* temp;
	char* tmpname;
	int len;
	len = strlen(Name);
	len = len + 1;
	temp = malloc(sizeof(struct node));
	tmpname = malloc(len * sizeof(char));
	strcpy(tmpname, Name);
	temp->word = tmpname;
	temp->count = 1;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
/*taking care of the node already being initalized outside this function*/
void BinaryTree(struct node* root, char* Name)
{
	int compair;
	compair = strcmp(Name, root->word);
	if(compair == 0)
	{
		printf("updating count: %s\n", Name);
		root->count = root->count + 1;
	}
	else if( compair < 0)
	{
		if(root->left == NULL)
		{
			printf("left add: %s\n", Name);
			root->left = AddNode(Name);
		}
		else
		{
			printf("going left\n");
			BinaryTree(root->left, Name);
		}
	}
	else if(compair > 0)
	{
		if(root->right == NULL)
		{
			printf("right add: %s\n", Name);
			root->right = AddNode(Name);
		}
		else
		{
			printf("going right\n");
			BinaryTree(root->right, Name);
		}
	}
}
void PrintTree(struct node* root)
{
	if(root != NULL)
	{
		PrintTree(root->left);
		printf("%s, %d\n", root->word, root->count);
		PrintTree(root->right);
	}
}
void FreeMemory(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	FreeMemory(root->left);
	FreeMemory(root->right);
	free(root);
}
