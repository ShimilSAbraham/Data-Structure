#include <stdio.h>

struct{
    int tuple[100][3];
    int row;
    int col;
    int val;
}A,B;
int triplet[100][3];

/* this function converts the matrix into triplet form*/

void to_triplet(int row,int col,int arr[row][col],int value)
{
    int i,j;
    triplet[0][0] = row;
    triplet[0][1] = col;
    triplet[0][2] = value;
    int k=1;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i][j]!=0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = arr[i][j];
                k+=1;
            }
        }
    }
}

/* this function adds and prints the tuple */

void add_sparse(int at[A.val][3],int bt[B.val][3])
{
    int apos=1,bpos=1,spos=1;
    while(apos<=A.val && bpos<=B.val)
        {
            if(at[apos][0] < bt[bpos][0] || (at[apos][0] == bt[bpos][0] && at[apos][1] < bt[bpos][1]))
            {
                for(int temp=0; temp<3; temp++)
                    triplet[spos][temp] = at[apos][temp];
                apos++;
            }
            else if(at[apos][0] > bt[bpos][0] || (at[apos][0] == bt[bpos][0] && at[apos][1] > bt[bpos][1]))
            {
                for(int temp=0; temp<3; temp++)
                    triplet[spos][temp] = bt[bpos][temp];
                bpos++;
            }
            else
            {
                triplet[spos][0] = at[apos][0];
                triplet[spos][1] = at[apos][1];
                triplet[spos][2] = at[apos][2] + bt[bpos][2];
                apos++;
                bpos++;
            }   
            spos++;
        }
    while(apos<=A.val)
    {
        for(int temp=0; temp<3; temp++)
        triplet[spos][temp] = at[apos][temp];
        apos++;
        spos++; 
    }
    while(bpos<=B.val)
    {
        for(int temp=0; temp<3; temp++)
        triplet[spos][temp] = bt[bpos][temp];
        bpos++;
        spos++; 
    }
    //triplet temporarily stores the tuples and then its values are transferred in the main function
    triplet[0][0] = at[0][0];
    triplet[0][1] = at[0][1];
    triplet[0][2] = spos-1;
    printf("The triplet of the sum of A and B are:\n");
    for(int i=0;i<spos;i++)
        printf("<\t%d\t%d\t%d\t>\n",triplet[i][0],triplet[i][1],triplet[i][2]);
    
}

void main()
{
    int i,j;

    /* initialising all the variables related to matrix A including the number of non-zero elements */

    printf("Enter the size of the matrix A (rows,columns):\n");
    scanf("%d %d",&A.row,&A.col);
    printf("Input the elements in the matrix:\n");
    int a[A.row][A.col];
    for(i=0;i<A.row;i++)
    {
        for(j=0;j<A.col;j++)
        {
        scanf("%d",&a[i][j]);
        if(a[i][j]!=0)
            A.val+=1;
        }
    }

    /* initialising all the variables related to matrix B including the number of non-zero elements */

    printf("Enter the size of the matrix B (rows,columns):\n");
    scanf("%d %d",&B.row,&B.col);
    printf("Input the elements in the matrix:\n");
    int b[B.row][B.col];
    for(i=0;i<B.row;i++)
    {
        for(j=0;j<B.col;j++)
        {
        scanf("%d",&b[i][j]);
        if(b[i][j]!=0)
            B.val+=1;
        }
    }
    /* to call the function and give the values to matrix A's tuple*/

    to_triplet(A.row,A.col,a,A.val);
    for(i=0;i<=A.val;i++)
        for(j=0;j<3;j++)
            A.tuple[i][j] = triplet[i][j];

    /* to print the tuple of A */

    printf("The triplets of matrix A are:\n<\trow\tcolumn\tvalue\t>\n");
    for(i=0;i<=A.val;i++)
        printf("<\t%d\t%d\t%d\t>\n",A.tuple[i][0],A.tuple[i][1],A.tuple[i][2]);

    /* to call the function and give the values to matrix B's tuple*/

    to_triplet(B.row,B.col,b,B.val);
    for(i=0;i<=B.val;i++)
        for(j=0;j<3;j++)
            B.tuple[i][j] = triplet[i][j];

    /* to print the tuple of B */

    printf("The triplets of matrix B are:\n<\trow\tcolumn\tvalue\t>\n");
    for(i=0;i<=B.val;i++)
        printf("<\t%d\t%d\t%d\t>\n",B.tuple[i][0],B.tuple[i][1],B.tuple[i][2]);

    /* adding two sparse matrix */

    if(A.row==B.row && A.col==B.col)
        add_sparse(A.tuple,B.tuple);
    else
        printf("Since the matrix size is not the same, they cannot be added");

}
