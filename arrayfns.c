#include <stdio.h>

int print(int n,int arr[n])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

int insert(int m,int arr[m])
{
    int n,k;
    printf("Enter the position where you want to insert the element:");
    scanf("%d",&n);
    printf("Enter the element:");
    scanf("%d",&k);
    for(int i=m-1;i>=n-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[n-1]=k;
    printf("Printing array after insertion...\n");
    print(m+1,arr);
    return m+1;
}

int delete(int i,int arr[i])
{
    int n;
    printf("Enter the position from where element is to be deleted:");
    scanf("%d",&n);
    for (int j=n;j<i;j++)
    {
        arr[j-1]=arr[j];
    }
    arr[i-1]=0;
    printf("Printitn garray after deletion...\n");
    print(i-1,arr);
    return i-1;
}

int search(int n,int arr[n])
{
    int k,flag=0;
    printf("Enter the element to be found:");
    scanf("%d",&k);
    for (int i=0;i<n;i++)
    {
        if (k==arr[i])
        {
            printf("Element %d found at pos %d\n",k,i+1);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("Element not found\n");
    }
    return 0;
}

int sort(int n,int arr[n])
{
    int temp=0,flag;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Printing array after sorting...\n");
    print(n,arr);
    return 0;
}

void main()
{
    int n,c,l;
    printf("Enter the number of elements to be entered in array:");
    scanf("%d",&n);
    int arr[50];
    printf("Reading array...\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    do
    {
        printf("Menu\n1. Insert\n2. Delete\n3. Search\n4. Sort\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                n=insert(n,arr);
                break;
            }
            case 2:
            {
                n=delete(n,arr);
                break;
            }
            case 3:
            {
                search(n,arr);
                break;
            }
            case 4:
            {
                sort(n,arr);
                break;
            }
            default:
            {
                printf("Error\n");
                break;
            }
        }
        printf("Do you want to continue(1/0)?");
        scanf("%d",&l);
    }
    while(l==1);
}