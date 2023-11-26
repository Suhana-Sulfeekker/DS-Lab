#include <stdio.h>
#define maxsize 10
 
void display(int stack[maxsize],int *top)
{
	printf("\nDisplaying the sorted stack..\n");
	for(int i=(*top);i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
 
int pop(int stack[maxsize],int *top)
{
	if (*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		int d=stack[(*top)--];
		return d;
	}
}
 
int push(int stack[maxsize],int auxstack[maxsize],int *auxtop,int *top)
{
	int n,temp;
	if ((*top)>=maxsize-1)
		printf("Stack is full\n");
	else if (*top==-1)
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&n);
		stack[++(*top)]=n;
	}
	else
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&n);
		if (stack[*top]>n)
			stack[++(*top)]=n;
		else
		{
			while (stack[*top]<n && (*top)>-1)
			{
				temp=pop(stack,top);
				auxstack[++(*auxtop)]=temp;				
			}
			stack[++(*top)]=n;
			while (*auxtop>-1)
			{
				temp=pop(auxstack,auxtop);
				stack[++(*top)]=temp;
			}
		}		
	}
	display(stack,top);
	return 0;
}
 
 
 
void main()
{
	int stack[maxsize],auxstack[maxsize];
	int c;
	int top=-1,auxtop=-1;
 
	do
	{
		printf("\n*****MENU*****\n1.PUSH\n2.EXIT\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				push(stack,auxstack,&auxtop,&top);
				break;
			}
			case 2:
			{
				printf("Exiting from Menu...\n");
				break;
			}
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	while (c!=2);
}