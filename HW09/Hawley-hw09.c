#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hw09-header.h"

struct node
{
	char name[15];
	char course[15];
	int line;
	struct node* next;
};

struct node* enqueue(char add[4][15]);/*create the node, populate the node, return the temp node to be assigned at main */
struct node* dequeue(struct node* TheQue);



int main(int argc, char* argv[])
{
	struct node* Que1 = NULL;/*treat as head*/
	struct node* Que2 = NULL;/*treat as head*/
	struct node* Que3 = NULL;/*treat as head*/
	struct node* end1;/*treat as tail*/
	struct node* end2;/*treat as tail*/
	struct node* end3;/*treat as tail*/
	struct node* intrum;
	int k = 0, key;
	char temp[4][15];
	char buffer[50];
	char* word;
	char* del = ",";
	
	key = atoi(argv[1]);
	initialize(key);
	
	strcpy(buffer, getString());
	while(strcmp(buffer,"stop") != 0)
	{
		word = strtok(buffer, del);
		while(word != NULL)
		{
			strcpy(temp[k], word);
			k = k + 1;
			word = strtok(NULL, del);
		}
		k = 0;
		if( strcmp(temp[0], "enqueue") == 0 )
		{
			if( atoi(temp[1]) == 1)
			{
				intrum = enqueue(temp);
				if(Que1 == NULL)
				{
					Que1 = intrum;
				}
				else
				{
					end1->next = intrum;
				}
				end1 = intrum;
			}
			else if( atoi(temp[1]) == 2)
			{
				intrum = enqueue(temp);
				if(Que2 == NULL)
				{
					Que2 = intrum;
				}
				else
				{
					end2->next = intrum;
				}
				end2 = intrum;
				
			}
			else if( atoi(temp[1]) == 3)
			{
				intrum = enqueue(temp);
				if(Que3 == NULL)
				{
					Que3 = intrum;
				}
				else
				{
					end3->next = intrum;
				}
				end3 = intrum;
				
			}
		}
		if( strcmp(temp[0], "dequeue") == 0 )
		{
			if( atoi(temp[1]) == 1)
			{
				if(Que1 != NULL)
				{
					dequeue(Que1);
				}
				else
				{
					printf("error the que is empty.\n");
				}
			}
			else if( atoi(temp[1]) == 2)
			{
				if(Que2 != NULL)
				{
					dequeue(Que2);
				}
				else
				{
					printf("error the que is empty.\n");
				}
				
			}
			else if( atoi(temp[1]) == 3)
			{
				if(Que3 != NULL)
				{
					dequeue(Que3);
				}
				else
				{
					printf("error the que is empty.\n");
				}
				
			}
		}
		strcpy(buffer, getString());
	}
	/*
	if( strcmp(buffer, "stop") == 0 )
	*/
	/*if the while loop breaks, that means a stop was revived*/
	printf("stop recived; prossesing remaining students\n");
	
	while(Que1 != NULL)
	{
		Que1 = dequeue(Que1);
	}
	while(Que2 != NULL)
	{
		Que2 = dequeue(Que2);
	}
	while(Que3 != NULL)
	{
		Que3 = dequeue(Que3);	
	}
		
	
}
struct node* enqueue(char add[4][15])
{
	struct node* temp;
	printf("%s enters line %s to register for %s\n", add[3], add[1], add[2]);
	temp = malloc(sizeof(struct node));
	strcpy(temp->name, add[3]);
	strcpy(temp->course, add[2]);
	temp->line = atoi(add[1]);
	temp->next = NULL;

	return temp;
}
struct node* dequeue(struct node* TheQue)
{
	struct node* temp = TheQue->next;
	printf("%s leaves line %d\n", TheQue->name, TheQue->line );
	/*
	free(TheQue);
	*/
	
	return temp;
}
