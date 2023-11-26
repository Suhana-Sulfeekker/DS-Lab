#include <stdio.h>
#define maxsize 10
 
void display(int stack[maxsize],int *top)
{
	printf("\nDisplaying the stack..\n");
	for(int i=(*top);i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
 
int peek(int stack[maxsize],int *top)
{
	return stack[*top];
}
 
 
int push(int stack[maxsize],int minstack[maxsize],int *topmin,int *top)
{
	int n;
	if ((*top)>=maxsize-1)
		printf("Stack is full\n");
	else if ((*top)==-1)
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&n);
		stack[++(*top)]=n;
		minstack[++(*topmin)]=n;				
	}
	else
	{
		printf("Enter the element to be pushed:");
		scanf("%d",&n);
		stack[++(*top)]=n;
		int d=peek(minstack,topmin);
		if (n<d)
		{
			minstack[++(*topmin)]=n;
		}
	}
	display(stack,top);
	return 0;
}
 
int pop(int stack[maxsize],int minstack[maxsize],int *topmin,int *top)
{
	if (*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		int d=stack[(*top)--];
		int k=peek(minstack,topmin);
		if (d==k)
			(*topmin)--;
		printf("Deleted element is %d\n",stack[(*top)+1]);
	}
	display(stack,top);
	return 0;
}
 
void main()
{
	int stack[maxsize],minstack[maxsize];
	int c;
	int top=-1,topmin=-1;
 
	do
	{
		printf("\n*****MENU*****\n1.PUSH\n2.POP\n3.DISPLAY\n4.MINIMUM ELEMENT\n5.PEEK\n6.EXIT\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				push(stack,minstack,&topmin,&top);
				break;
			}
			case 2:
			{
				pop(stack,minstack,&topmin,&top);
				break;
			}
			case 3:
			{
				display(stack,&top);
				break;
			}
			case 4:
			{
				int min=peek(minstack,&topmin);
				printf("The minimum element of stack=%d\n",min);
				break;
			}
			case 5:
			{
				int d=peek(stack,&top);
				printf("Topmost element =%d\n",d);
				break;
			}
			case 6:
			{
				printf("Exiting from Menu...\n");
				break;
			}
			default:
				break;
		}
	}
	while (c!=6);
}