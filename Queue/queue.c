#include <stdio.h>
#include <string.h>
int rear=-1, front=-1;
int queue[5];

int isEmpty()
{
    if(front>rear || front<0)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear==4) // 4 because size-1
        return 1;
    else
        return 0;
}

void enqueue(int a)
{
    if(isFull()==0)
    {
        if(front<0)
            front++;
        queue[++rear] = a; 
        printf("%d was added to the rear\n",queue[rear]);
    }
    else
        printf("The queue is full\n"); 
}

void dequeue()
{
    if(isEmpty()==0)
    {
        printf("%d was removed from the front\n",queue[front]); 
        ++front;
    }
    else
    {
        printf("The queue is empty\n");
        rear = -1;
        front = -1;
    }  
}

void main()
{
    char check[] = "yes";
    int op,item;
    while(strcmp(check,"yes") == 0)
    {
        printf("Enter 1 to enqueue, 2 to dequeue:\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("Enter the number to be queued:\n");
            scanf("%d",&item);
            enqueue(item);
        }
        else if(op==2)
        {
            dequeue();
        }
        else
            printf("Wrong input\n");

        printf("Do you want to do more operations:type yes or no\n");
        scanf("%s",check);
    }  
}
