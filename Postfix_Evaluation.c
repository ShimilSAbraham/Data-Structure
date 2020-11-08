#include<stdio.h>
#include<string.h>

char input[100];
int infix[20];
int top =-1;

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int peek()
{
    if(isEmpty()==0)
        return infix[top];
}

void push(int n)
{
    infix[++top] = n;
}

int pop()
{
    if(isEmpty()==0)
        return infix[top--];
}

//performs the appropriate operation and pushes it to the stack
int perform(char op)
{
    int next;
    int op2 = pop();
    int op1 = pop();
    switch(op)
    {
        case '+':
        next = op1+op2;
        break;

        case '-':
        next = op1-op2;
        break;

        case '*':
        next = op1*op2;
        break;

        case '/':
        next = op1/op2;
        break;
    }
    push(next);
}

//extracts each number from the whole string and pushes it to the stack
void extract(int start,int end)
{
    int x=0;
    char integer[4];
    while(start<end)
    {
        integer[x]=input[++start];
        x++;
    }
    sscanf(integer,"%d",&x); 
    push(x);
    
}
            
void main()
{
    int i,len;
    printf("Input the postfix expression with space in between each numbers and symbols:\n");
    gets(input);

    len = strlen(input);
    int j = -1;
    for(i=0;i<len;i++)
    {
        char ch = input[i];
        //if ch is an operator
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            perform(ch);
            j = i+1;
            i++;
        } 
        //if ch is a space
        if((int)(ch)==32)
        {
            extract(j,i);
            j=i;
        }      
    }  
    printf("The evaluated value is : %d \n",peek());
}
