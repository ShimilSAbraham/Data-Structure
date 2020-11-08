#include <stdio.h>
#include <string.h>

char stack[50] = "";
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
    printf("%c is on top of the stack\n", stack[top]);
}

void push(char ch)
{
    if(ch!=' ')
        printf("%c was pushed into the stack\n", ch);
    stack[++top] = ch;
}

char pop()
{
    printf("%c was poped out of the stack\n", stack[top]);
    return stack[top--];
}

void main()
{
    int i,j;
    char input[50];
    printf("Input the postfix expression:\n");
    scanf("%s",input);
    int len = strlen(input);

    strlwr(input);      //to lowercase

    for(i=0;i<len;i++)
    {
        int ch_no = (int)(input[i]);
        if(ch_no>96 && ch_no<123)
        {
            push(input[i]);
            push(' ');
        }
        else
        {
            for(j=top-1; j>0; j--)
            {
                if(stack[j]==' ')
                {
                    stack[j] = input[i];
                    break;
                }
            }
        }
    }
    printf("\nThe infix expression is %s\n",stack);
}
