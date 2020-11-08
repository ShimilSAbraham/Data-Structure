#include <stdio.h>
struct {
    int row;
    int col;
    int val;
    int tuple[100][3];
}A,B;
int M_tuple[100][3];
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

/* this function multiplies the two sparse tuples */

void multiply()
{
    int apos,bpos,fpos=1;
    int M_fake[100][3];
    //nested for loops to make a tuple matrix having every possible row and column in the product
    for(apos=1;apos<=A.val;apos++)
    {
        for(bpos=1;bpos<=B.val;bpos++)
        {
            if(A.tuple[apos][1]==B.tuple[bpos][0])
            {
                M_fake[fpos][0] = A.tuple[apos][0];
                M_fake[fpos][1] = B.tuple[bpos][1];
                M_fake[fpos][2] = A.tuple[apos][2] * B.tuple[bpos][2];
                fpos++;
            }
        }
    }    
    //removing the duplicates by adding the repeated row and column values
    for(int i=1; i<fpos; i++)
    {
        for(int j=i+1; j<fpos; j++)
        {
            if(M_fake[i][0]==M_fake[j][0] && M_fake[i][1]==M_fake[j][1])
            {
                M_fake[i][2]+=M_fake[j][2];
                M_fake[j][2] = 0;
            }
        }
    }
    int mpos = 1;
    //this loop creates the real product tuple
    for(int i=1; i<fpos; i++)
    {
        if(M_fake[i][2]!=0)
        {
            M_tuple[mpos][0] = M_fake[i][0];
            M_tuple[mpos][1] = M_fake[i][1];
            M_tuple[mpos][2] = M_fake[i][2];
            mpos++;
        }
    }
    M_tuple[0][0] = A.row;
    M_tuple[0][1] = B.col;
    M_tuple[0][2] = mpos-1;
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
    
    if(A.col==B.row)
    {
        multiply();
        printf("Tuple of M:\n");
        for(int i=0;i<=M_tuple[0][2];i++)
            printf("<\t%d\t%d\t%d\t>\n",M_tuple[i][0],M_tuple[i][1],M_tuple[i][2]);
    }
    else
    {
        printf("The two matrices cannot be multiplied");
    }
    

}
