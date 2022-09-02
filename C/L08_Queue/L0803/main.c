#include <stdio.h>
#include "priorityQueue.h"

int main(){
    int usr_input,i;
    printf("------------Priority Queue----------------\n");
    printf("------------EnqueuePQ (num)-----------\n");
    for(i=0;i<5;i++)
    {
        printf("EnqueuePQ (num) : ");
        scanf("%d",&usr_input);
        enqueuePQ(usr_input);
    }
    printf("---------------Dequeue()-----------------\n");
    printf("Dequeue : ");
    for(i=0;i<5;i++)
    {
        printf("%d ",dequeue());
    }
    printf("\n------------Enqueue (num)-----------\n");
    for(i=0;i<5;i++)
    {
        printf("Enqueue (num) : ");
        scanf("%d",&usr_input);
        enqueue(usr_input);
    }
    printf("---------------DequeuePQ-----------------\n");
    printf("DequeuePQ : ");
    for(i=0;i<5;i++)
    {
        printf("%d ",dequeuePQ());
    }
}