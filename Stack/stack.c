#include <stdio.h>
#include <string.h>

int stack[100];
int top =-1;

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void peek()
{
    printf("%d is on top of the stack\n", stack[top]);
}

void push(int i)
{
    printf("%d was pushed into the stack\n", i);
    stack[++top] = i;
}

void pop()
{
    printf("%d was poped out of the stack\n", stack[top]);
    top--;
}

void displayStack(int a)
{
    while(a!=-1)
    {
        printf("%d\n",stack[a--]);
    }
}

void main()
{
    char check[] = "yes";
    
    while(strcmp(check,"yes") == 0)
    {
        char op[20];
        printf("Enter peek to peek, push to push and pop to pop an item from the stack:\n");
        scanf("%s", op);
        if(strcmp(op,"peek") == 0)
        {
            if(top!=-1)
                peek();
            else
                printf("The stack has nothing to be peeked\n");
        }
            
        else if(strcmp(op,"pop") == 0)
        {
            if(isEmpty()==0)
                pop();
            else
                printf("The stack is empty\n");
        }
        else if(strcmp(op,"push") == 0)
        {
            printf("Enter the number to be pushed:\n");
            int item;
            scanf("%d",&item);
            push(item);
        }
        else
            printf("Wrong input\n");

        printf("Do you want to do more operations:type yes or no\n");
        scanf("%s",check);
    }
    //display final stack
    displayStack(top);
    
}
