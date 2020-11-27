#include <stdio.h>

struct poly{
    int size;
    int coeff[50];
    int pow[50];
}A,B,C;

void Ainput()
{
    printf("Enter the number of terms in polynomial A:\n");
    scanf("%d",&A.size);
    printf("Enter the coefficient and power of each term in the polynomial A in descending order:\n");
    for(int i=0;i<A.size;i++)
        scanf("%d %d",&A.coeff[i],&A.pow[i]);
}

void Binput()
{
    printf("Enter the number of terms in polynomial B:\n");
    scanf("%d",&B.size);
    printf("Enter the coefficient and power of each term in the polynomial B in descending order:\n");
    for(int i=0;i<B.size;i++)
        scanf("%d %d",&B.coeff[i],&B.pow[i]);
}

void Cappend()
{
    int locA=0,locB=0,locC=0;
    while(locA<A.size && locB<B.size)
    {
        //equal exponents
        if(A.pow[locA]==B.pow[locB])
        {
            C.pow[locC] = A.pow[locA];
            C.coeff[locC++] = A.coeff[locA++] + B.coeff[locB++];
        }
        //A has greater power than B
        else if(A.pow[locA]>B.pow[locB])
        {
            C.pow[locC] = A.pow[locA];
            C.coeff[locC++] = A.coeff[locA++];
        }
        else
        {
            C.pow[locC] = B.pow[locB];
            C.coeff[locC++] = B.coeff[locB++];
        }
    }
    //if A has excess terms
    while(locA<A.size)
    {
        C.pow[locC] = A.pow[locA];
        C.coeff[locC++] = A.coeff[locA++];
    }
    //if B has excess terms
    while(locB<B.size)
    {
        C.pow[locC] = B.pow[locB];
        C.coeff[locC++] = B.coeff[locB++];
    }
    C.size = locC; 
}

void display(int s,int c[s],int p[s])
{
    for(int i=0;i<s;i++)
    {
        if(i<(s-1))
        {
            if(c[i]==1)
                printf("X^%d + ",p[i]);
            else
                printf("%dX^%d + ",c[i],p[i]);
        }
        else
        {
            if(p[i]==0)
                printf("%d\n",c[i]);
            else
                printf("%dX^%d\n",c[i],p[i]);
        }
    }
}

void main()
{
    Ainput();
    printf("The Polynomial A is :\n");
    display(A.size,A.coeff,A.pow);
    Binput();
    printf("The Polynomial B is :\n");
    display(B.size,B.coeff,B.pow);
    Cappend();
    printf("The Polynomial Addition is :\n");
    display(C.size,C.coeff,C.pow);
}
