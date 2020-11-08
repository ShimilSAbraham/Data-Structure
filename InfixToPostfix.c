#include <stdio.h>
#include <string.h>

char stack[50] = "";
char postfix[50] = "";
int top =-1, p_index=0;

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
        return stack[top];
}

void push(char ch)
{
    stack[++top] = ch;
}

int pop()
{
    if(isEmpty()==0)
    {
        return stack[top--];
    }
}

//used for returning priority values of operators
int priority(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return -1;
}

//returns 1 if the top value of stack is having more precedence than checked operator
//if its true it means it will pop the top value of stack to postfix exp
int precedence(char ch1,char ch2)
{
    int ch1_pri = priority(ch1);
    int ch2_pri = priority(ch2);
    
    if(ch1_pri>=ch2_pri)
        return 1;
    if(ch1_pri<ch2_pri)
        return 0;   
}

void main()
{
    int i;
    char input[50];
    
    printf("Input the infix expression:\n");
    scanf("%s",input);
    int len = strlen(input);

    //to lowercase
    strlwr(input);      
    
    for(i=0;i<len;i++)
    {
        char ch = input[i];
        int ascii = (int)(ch); /*contains ascii of the character*/

        //checking if the character is a lower case alphabet
        //if yes it will be appended to the postfix string
        if(ascii>96 && ascii<123)
        {
            postfix[p_index++] = ch;
        }
        else
        {
            if(isEmpty() || ch=='(')
                push(ch);
            
            //executes the operators within paranthesis
            else if(ch==')')
            {
                while(peek()!='(')
                    postfix[p_index++] = pop();
                pop();
            }

            //precedence check
            else
                {
                    while(isEmpty()==0 && precedence(peek(),ch))
                        postfix[p_index++] = pop();
                    push(ch);
                }
        }
    }

    //remaining operators appended to the postfix exp
    while(isEmpty()==0)
        postfix[p_index++] = pop();
    
    printf("The postfix string is:\n%s\n",postfix);
}
