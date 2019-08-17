/*
    Darin Brezeale
    CSE 1320, hw #6
    Thu Feb 20 20:34:26 CST 2014

    Read a file of classes from stdin, storing each line in an array of structures.
	Print out the results in a 2D table of times versus rooms.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
CSE 3313 - INTRODUCTION TO SIGNAL PROCESSING, 001-LEC(24252), MoWe 10:30AM - 11:50AM, ERB 129, Darin Brezeale, 01/13/2014 - 05/02/2014
*/

struct courses {
    char name[10];
    char title[70];
    char id[20];
    char time[25];
    char room[10];
    char instructor[30];
    /* char dates[25];  don't need at this time */
};
/* adds to 190 with dates, round to 200 for commas */


int readData(struct courses d[]);
void bubblesort(struct courses d[], int numCourses);
void printTable(struct courses d[], int numCourses);
void testing(struct courses d[], int numCourses);

int main(int argc, char* argv[])
{
    struct courses d[100];
    int numCourses;

    numCourses = readData(d);
    bubblesort(d, numCourses);

    /* print results or stored data; useful for testing */
    if ( argc != 2 )
    {
        printTable(d, numCourses);
    }
    else
        testing(d, numCourses);

    return 0;
}

void testing(struct courses d[], int numCourses)
/*
      input:  array of structures
     output:  int, count of courses added
    purpose:  display contents of array of structures;
              it helps with debugging
*/
{
    int i;

    for(i = 0; i < numCourses; i++)
        printf("%s, %s, %s\n", d[i].time, d[i].name, d[i].room);
}


int readData(struct courses d[])
/*
      input:  array of structures
     output:  int, count of courses added
    purpose:  read file, storing courses in an array of structures

    char name[10];
    char title[70];
    char id[20];
    char time[25];
    char room[10];
    char instructor[30];

*/
{
    char buffer[200];
    char tempRoom[10];
    char *del = ",\n", *temp;
    struct courses tempStruct;
    int count = 0;

    while( fgets(buffer, sizeof(buffer), stdin) != NULL )
    {
        /* store line in temporary structure */
        strcpy(tempStruct.name, strtok(buffer, del));
        strcpy(tempStruct.title, strtok(NULL, del));
        strcpy(tempStruct.id, strtok(NULL, del));
        strcpy(tempStruct.time, strtok(NULL, del));
        strcpy(tempStruct.room, strtok(NULL, del));
        strcpy(tempStruct.instructor, strtok(NULL, del));

        strcpy(tempRoom, tempStruct.room);
        temp = strtok(tempRoom, " ");  /* get building */
        if( strcmp(temp, "ERB") == 0 )
        {
            d[count] = tempStruct;
            count++;
        }
    }

    return count;
}


void printTable(struct courses d[], int numCourses)
/*
      input:  array of structures
     output:  int, count of courses added
    purpose:  prints comma-delimited results
*/
{
    char* loc[] = {"ERB 103", "ERB 106", "ERB 126", "ERB 127", "ERB 129", "ERB 130", "ERB 131"};
    char currentTime[25] = "";
    int i, k, index, size = sizeof(loc)/sizeof(loc[0]);

    for(i = 0; i < numCourses; i++)
    {
        if( strcmp(currentTime, d[i].time) != 0 )
        {
            if(i != 0)
                printf("\n");

            printf("%s", d[i].time);
            strcpy(currentTime, d[i].time);
            index = 0;
        }

        for(k = index; k < size; k++)
            if( strcmp(loc[k], d[i].room) == 0 )
            {
                printf(", %s-%s", d[i].name, d[i].room);
                index = k+1;
                break;
            }
            else
                printf(", ");
    }
    printf("\n");
}


void bubblesort(struct courses d[], int numCourses)
/*
      input:  array of structures
              int, number of structures
     output:  nothing
    purpose:  sort array of structures
*/
{
    int i, unsorted;
    struct courses temp;

    do
    {
        unsorted = 0;  /*  0 = False  */
        for(i = 0; i < numCourses-1; i++)
            if(
                ( strcmp(d[i].time, d[i+1].time) > 0 ) ||
                ( strcmp(d[i].time, d[i+1].time) == 0 &&
                  strcmp(d[i].room, d[i+1].room) > 0 )       
              ) 
            {
                temp = d[i];
                d[i] = d[i+1];
                d[i+1] = temp;
                unsorted = 1;  /*  1 = False  */
            }
    }
    while(unsorted);
}


