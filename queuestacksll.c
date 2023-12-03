#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	int data;
	struct nd* next;
}node;
 
node *front=NULL,*rear=NULL,*top=NULL;
 
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
 
void push(int data){
	node *temp;
	node *newnode=(node*)malloc(sizeof(node));
	if(top==NULL){
		top=newnode;
		newnode->data=data;
		newnode->next=NULL;
	}
	else{
		temp=top;
		top=newnode;
		newnode->data=data;
		newnode->next=temp;		
	}	
}
 
int pop(){
	int d=0;
	if (top==NULL)
		printf("Stack empty\n");
	else{
		node *temp;
		temp=top;
		d=temp->data;
		top=top->next;
		free(temp);
		return d; 		
	}
 
}
 
void enqueue(int data){
	node *newnode=(node*)malloc(sizeof(node));
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
}
 
int dequeue(){
	int d=0;
	if (rear==NULL){
		printf("Queue empty.\n");}
	else if (front!=rear){
		node *temp;
		temp=front;
		front=front->next;
		d=temp->data;
		free(temp);
		return d;
	}
	else if (front==rear){
		node *temp;
		temp=rear;
		d=temp->data;
		rear=front=NULL;
		free(temp);	
		return d;	
	}
}
 
void reverseq(){
	int d=0;
	while(front!=NULL && rear!=NULL){
		d=dequeue();
		push(d);
	}
	while(top!=NULL){
		d=pop();
		enqueue(d);
	}
	display();
}
 
void main(){
	int c;
	do{
		printf("MENU\n1.Enqueue\n2.Dequeue\n3.Reverse the queue\n4.Display\n5.Exit\nEnter Choice:");
		scanf("%d",&c);
		switch(c){
			case 1:{
				int data;
				printf("Enter the element to be enqueued:");
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				reverseq();
				break;
			}
			case 4:{
				display();
				break;
			}
			case 5:{
				printf("Exiting Pgm...\n");
				break;
			}
		}
	}
	while(c!=5);
}