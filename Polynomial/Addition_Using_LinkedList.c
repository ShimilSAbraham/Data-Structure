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
    countC++;
    newnode=(struct poly*)malloc(sizeof(struct poly));
    newnode->coeff=c;
    newnode->pow=p;
    newnode->next=NULL;
    if(startC==NULL)
        startC=newnode;
    else
    {
        temp=endC;
        temp->next=newnode;        
    }
    endC=newnode;
}
void addition()
{
    struct poly *tempA,*tempB;
    tempA=startA;
    tempB=startB;
    int c,p;
    while(tempA!=NULL && tempB!=NULL)
    {
        //if powers of A and B are equal
        if((tempA->pow)==(tempB->pow))
        {
            c=((tempA->coeff)+(tempB->coeff));
            p=(tempA->pow);
            tempA=(tempA->next);
            tempB=(tempB->next);
        }
        //if A's power greater than B
        else if((tempA->pow)>(tempB->pow))
        {
            c=(tempA->coeff);
            p=(tempA->pow);
            tempA=(tempA->next);
        }
        else
        {
            c=(tempB->coeff);
            p=(tempB->pow);
            tempB=(tempB->next);
        }
        create_polyC(c,p);
    }
    //remaining elements in polynomial A
    while (tempA!=NULL)
    {
        c=tempA->coeff;
        p=tempA->pow;
        tempA=tempA->next;
        create_polyC(c,p);
    }
    //remaining elements in polynomial B
    while (tempB!=NULL)
    {
        c=tempB->coeff;
        p=tempB->pow;
        tempB=tempB->next;
        create_polyC(c,p);
    }
}

void display(struct poly *start)
{
    temp=start;
    while(temp!=NULL)
    {
        //skips the present iteration if the coefficient is 0
        if(temp->coeff==0)
        {
            temp=temp->next;
            continue;
        }
        else if(temp->pow==0)
            printf("%d ",temp->coeff);
        else if(temp->coeff==1)
            printf("x^%d",temp->pow);
        else
            printf("%dx^%d ",temp->coeff,temp->pow);
        temp=temp->next;
        if(temp!=NULL)
            printf("+ ");
    }
    printf("\n\n");
}

void main()
{
    printf("Enter the polynomial A in its descending order of power:\n");
    create_polyA();
    printf("The polynomial A contains: ");
    display(startA);
    printf("Enter the polynomial B in its descending order of power:\n");
    create_polyB();
    printf("The polynomial B contains: ");
    display(startB);
    printf("\nThe sum of two polynomials: ");
    addition();
    display(startC);
}
