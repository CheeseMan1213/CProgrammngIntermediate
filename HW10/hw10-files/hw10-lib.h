/* put your function declarations, structure definitions, #defines, etc.
   in this file

   each file needing any of those things should include this file.

   below are some examples
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct sample {
    int one;
    double two;
};
*/
struct Roster /*for some reason you can only have one structure definition*/
{
	char Name[16];
	char Course[10];
};

void f(int a, int b);
int GetData(FILE* data, struct Roster TheArray[]);
int GetNames(FILE* names, char TheArray[][16]);
void PrintData(struct Roster TheArray[], int size);
void PrintNames(char TheArray[][16], int size);
void sort(struct Roster TheArray[], int size);
int BinarySearch(struct Roster SortedArray[], int low, int high, char FindMe[16]);
int GetDataAgain(char TheArray[][30], int size, char Again[][30]);
