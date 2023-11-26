#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	int data;
	struct nd* next;
}node;
 
node *front=NULL,*rear=NULL;
 
void display(){
	if (rear==NULL)
		printf("Queue empty\n");
	else{
		node *temp;
		temp=front;
		printf("Queue:");
		while (temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;		
		}
		printf("\n");		
	}
}
 
void enqueue(){
	node *newnode=(node*)malloc(sizeof(node));
	int data;
	printf("Enter the data:");
	scanf("%d",&data);
	if (rear==NULL){
		rear=front=newnode;
		newnode->data=data;
		newnode->next=NULL;
	}
	else{
		rear->next=newnode;
		newnode->data=data;
		rear=newnode;
		newnode->next=NULL;	
	}
	display();
}
 
void dequeue(){
	if (rear==NULL)
		printf("Queue empty\n");
	else if (front!=rear){
		node *temp;
		temp=front;
		front=front->next;
		printf("Deleted element:%d\n",temp->data);
		free(temp);
		display();
	}
	else if (front==rear){
		node *temp;
		temp=rear;
		printf("Deleted element:%d\n",rear->data);
		rear=front=NULL;
		free(temp);	
		display();	
	}
}
 
void main(){
	int c;
	do{
		printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&c);
		switch(c){
			case 1:{
				enqueue();
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				printf("Exiting pgm..\n");
				break;
			}
		}
	}
	while(c!=4);
}