#include <stdio.h>

int row,col,val=0;
int triplet[100][3];

/* this function converts the matrix into triplet form*/

void to_triplet(int row, int col, int arr[row][col])
{
    int i,j;
    triplet[0][0] = row;
    triplet[0][1] = col;
    triplet[0][2] = val;
    int k=1;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i][j]!=0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k++][2] = arr[i][j];
            }
        }
    }
}

void main()
{
    int i,j;
    printf("Enter the size of the matrix (rows,columns):\n");
    scanf("%d %d",&row,&col);
    printf("Input the elements in the matrix:\n");
    int arr[row][col];

    /* inputting elements in matrix A */
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
        scanf("%d",&arr[i][j]);
        if(arr[i][j]!=0)
            val++;
        }
    }

    to_triplet(row,col,arr);   //calling the converting function

    /* displaying tuple form of matrix A */
    printf("The triplets are:\n<\trow\tcolumn\tvalue\t>\n");
    for(i=0;i<=val;i++)
    {
        printf("<\t%d\t%d\t%d\t>\n",triplet[i][0],triplet[i][1],triplet[i][2]);
    }

    /* intialising elements in matrix B with 0 */
    int trans[col][row];
    for(i=0;i<col;i++)
        for(j=0;j<row;j++)
            trans[i][j] = 0;
    
    //assigning the values of non-zero elements in A to B
    for(i=1;i<=val;i++)
    {
        int c = triplet[i][0] ;
        int r = triplet[i][1] ;
        trans[r][c] = triplet[i][2] ;
    }

    //display the matrix of the transpose
    printf("The transpose is:\n");
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
        

    to_triplet(col,row,trans);   //calling the converting function

    /* displaying tuple form of matrix B */
    printf("The triplets of the transpose are:\n<\trow\tcolumn\tvalue\t>\n");
    for(i=0;i<=val;i++)
    {
        printf("<\t%d\t%d\t%d\t>\n",triplet[i][0],triplet[i][1],triplet[i][2]);
    }

}
