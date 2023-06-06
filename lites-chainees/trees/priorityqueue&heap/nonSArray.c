#include <stdio.h>
#include <stdlib.h>
//

/* our implimentation in a priority queue with a non sorted array , we will based on those points:
    -tas min the table is sorted from the largest to the smallest to save the O(1) time complexity
    -we will use a variable to know the size of the table
    -we will use a variable to know the capacity of the table
    -we will use a variable to know the number of elements in the table
    -we will use a function to add an element to the table (the smales element will be in the last index)
    -we will use a function to remove the smallest element from the table(go to the last index and remove it)
    -we will use a function to display the table
    -we will use a function to know if the table is empty or not
    -we will use a function to know if the table is full or not
    -we will use a daynamique allocation to increase the capacity of the table if it's full
    -we will use a function to free the table
    -we will use a function to get the smallest element from the table
*/

typedef struct
{
    int *table;
    int size;     // the number of elements in the table
    int capacity; // the capacity of the table
} priorityQueue;

priorityQueue *creatPriorityQueue(int capacity)
{
    priorityQueue *pq = (priorityQueue *)malloc(sizeof(priorityQueue));
    pq->table = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}
int isEmpty(priorityQueue *pq)
{
    return pq->size == 0;
}
int isFull(priorityQueue *pq)
{
    return pq->size == pq->capacity;
}
void add(priorityQueue *pq, int value)
{
    if (isFull(pq))
    {
        printf("the table is full\n");
        return;
    }
    pq->table[pq->size] = value;
    pq->size++;
}
