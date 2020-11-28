#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coeff;
    int pow;
    struct poly *next;
};
struct poly *newnode,*temp;
struct poly *startA=NULL,*endA=NULL;
struct poly *startB=NULL,*endB=NULL;
struct poly *startC=NULL,*endC=NULL;
int countA=0,countB=0,countC=0;

void addNode(int a)
{
    int c,p;
    newnode = (struct poly*)malloc(sizeof(struct poly));
    printf("Enter the coefficient and power of the current term: ");
    scanf("%d %d",&c,&p);
    newnode->coeff=c;
    newnode->pow=p;
    newnode->next=NULL;
    //poly A
    if(a==1)
    {
        countA++;
        if(startA==NULL)
        {
            startA=newnode;
            endA=newnode;
        }
    }
    //poly B
    if(a==2)
    {
        countB++;
        if(startB==NULL)
        {
            startB=newnode;
            endB=newnode;
        }
    }
}

void create_polyA()
{
    int check=1;
    while(check!=0)
    {
        addNode(1);
        if(countA!=1)
        {
            temp=endA;
            temp->next=newnode;
            endA=newnode;
        }
        printf("Do you want to add more terms(Type 1 for Yes & 0 for No): ");
        scanf("%d",&check);
    }  
}

void create_polyB()
{
    int check=1;
    while(check!=0)
    {
        addNode(2);
        if(countB!=1)
        {
            temp=endB;
            temp->next=newnode;
            endB=newnode;
        }
        printf("Do you want to add more terms(Type 1 for Yes & 0 for No): ");
        scanf("%d",&check);
    }   
}

void create_polyC(int c,int p)
{
    ++countC;
    newnode=(struct poly*)malloc(sizeof(struct poly));
    newnode->coeff=c;
    newnode->pow=p;
    newnode->next=NULL;
    if(startC==NULL)
    {
        startC=newnode;
        endC=newnode;
    }
    else
    {
        temp=startC;
        while(temp->pow!=p && temp->next!=NULL)
            temp=temp->next;
        if(temp->pow==p)
        {
            --countC;
            (temp->coeff)+=c;
            free(newnode);
        }
        else
        {
        temp=endC;
        temp->next=newnode;
        endC=newnode;
        }        
    }
}

void multiplication()
{
    struct poly *tempA,*tempB;
    int c,p;
    for(tempA=startA;tempA!=NULL;tempA=tempA->next)
    {
        for(tempB=startB;tempB!=NULL;tempB=tempB->next)
        {
            c=(tempA->coeff)*(tempB->coeff);
            p=(tempA->pow)+(tempB->pow);
            create_polyC(c,p);
        }
    }
}

void display(struct poly *start,int c)
{
    temp=start;
    int i=1;
    while(temp!=NULL)
    {
        //skips the present iteration if the coefficient is 0
        if(temp->coeff==0)
        {
            temp=temp->next;
            continue;
        }
        //if power is zero no need to print x^0 and + since it will be at the end
        else if(temp->pow==0)
            printf("%d ",temp->coeff);
        //if coefficient is 1 no need to print coefficient
        else if(temp->coeff==1)
            printf("x^%d ",temp->pow);
        else
            printf("%dx^%d ",temp->coeff,temp->pow);
        temp=temp->next;
        if((i++)<c)
            printf("+ ");
    }
    printf("\n\n");
}

void main()
{
    printf("Enter the polynomial A in its descending order of power:\n");
    create_polyA();
    printf("The polynomial A contains: ");
    display(startA,countA);
    printf("Enter the polynomial B in its descending order of power:\n");
    create_polyB();
    printf("The polynomial B contains: ");
    display(startB,countB);
    
    multiplication();
    printf("\nThe sum of two polynomials: ");
    display(startC,countC);
    
}
