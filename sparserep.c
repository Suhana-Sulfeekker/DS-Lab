#include <stdio.h>
int readspararr(int row,int col,int arr[row][col])
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    return 0;
}

int sparrep(int row,int col,int arr[row][col],int s[10][10])
{
    int k=1,i,j;
    s[0][0]=row;s[0][1]=col;s[0][2]=k;
    for (i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if (arr[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=arr[i][j];
                k++;
            }
        }
    }
    s[0][2]=k-1;
    return k-1;
}

int printspars(int k,int s[10][10])
{
    int i,j;
    for (i=0;i<=k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

void main()
{
    int row,col;
    printf("Enter the no of rows and columns:");
    scanf("%d %d",&row,&col);
    int arr[row][col],i,j;
    printf("Reading sparse matrix..\n");
    readspararr(row,col,arr);
    int s[10][10];
    int k1=sparrep(row,col,arr,s);
    printf("Printing sparse representation..\n");
    printspars(k1,s);
    printf("Finding sparcity..\n");
    float n=row*col;
    float spar=((n-k1)/n);
    printf("Sparcity=%.2f\n",spar);
}

