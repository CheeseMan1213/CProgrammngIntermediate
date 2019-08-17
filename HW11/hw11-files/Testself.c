/*
James Hawley 
20140421
TestSelf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
	char* word;
	int count;
	struct node* left;
	struct node* right;
};

struct node* addnode(char* name);
void PrintTree(struct node * root);
void BT(struct node* root, char* name);

int main(void)
{
	char* word;
	char* del = " \n";
	char buffer[1000];
	struct node* root = NULL;


	while( (fgets(buffer, sizeof(buffer), stdin)) != NULL)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			/*
			printf("%s\n", word);
			*/
			if(root == NULL)
			{
				root = addnode(word);
			}
			else
			{
				BT(root, word);
			}
			word = strtok(NULL, del);
		}
	}
	PrintTree(root);
}
struct node* addnode(char* name)
{
	struct node* temp;
	temp = malloc(sizeof(struct node));
	temp->count = 1;
	temp->word = name;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
void PrintTree(struct node* root)
{
	if(root != NULL)
	{
		PrintTree(root->left);
		printf("%s: %d\n", root->word, root->count);
		PrintTree(root->right);
	}
}
void BT(struct node* root, char* name)
{
	int compair;
	compair = strcmp(name, root->word);
	if(compair == 0)
	{
		root->count = root->count + 1;
	}
	else if(compair < 0)
	{
		if(root->left == NULL)
		{
			root->left = addnode(name);
		}
		else
		{
			BT(root->left, name);
		}
	}
	else if(compair > 0)
	{
		if(root->right == NULL)
		{
			root->right = addnode(name);
		}
		else
		{
			BT(root->right, name);
		}
	}
}
