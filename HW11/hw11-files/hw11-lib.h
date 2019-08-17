/* put your function declarations, structure definitions, #defines, etc.
   in this file

   each file needing any of those things should include this file.

   below are some examples
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
struct node* AddNode(char* Name);
void BinaryTree(struct node* root,char* Name);
void PrintTree(struct node* root);
void FreeMemory(struct node* root);
