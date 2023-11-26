#include <stdio.h>

struct Student
{
    char name[20];
    int rno;
    int marks[5];
    int tot;
}temp,s[50];

int sort(int n)
{
    int flag;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            flag=0;
            if (s[j].tot<s[j+1].tot)
            {
                flag=1;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
        if (flag==0)
        {
            break;
        }
    }
    return 0;
}

int print(int n)
{
    printf("No.\tName\tR No.\tTotal marks\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s\t%d\t%d\n",i+1,s[i].name,s[i].rno,s[i].tot);
    }
    return 0;
}

void main()
{
    int n,i,j;
    printf("Enter the number of students:");
    scanf("%d",&n);
    printf("Reading student details and marks..\n");
    for (i=0;i<n;i++)
    {
        printf("Enter name:");
        scanf("%s",s[i].name);
        printf("Enter roll no:");
        scanf("%d",&s[i].rno);
        s[i].tot=0;
        for(j=0;j<5;j++)
        {
            printf("Enter marks of sub %d:",j+1);
            scanf("%d",&s[i].marks[j]);
            s[i].tot=s[i].tot+s[i].marks[j];
        }
        printf("Total marks:%d\n",s[i].tot);
    }
    sort(n);
    printf("Printing sorted list (descending order)\n");
    print(n);
}