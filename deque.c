#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	int data;
	struct nd* next;
	struct nd* prev;
}Q;
 
Q *front=NULL,*rear=NULL;
 
void display(){
	Q *temp=front;
	if (temp==NULL)
		printf("Empty Queue\n");
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
 
void insertf(){
	int data;
	printf("Enter the data to enqueue:");
	scanf("%d",&data);
	Q *newnode=(Q*)malloc(sizeof(Q));
	if (front==NULL){
		front=rear=newnode;
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else{
		newnode->next=front;
		newnode->prev=NULL;
		newnode->data=data;
		front=newnode;
	}
	display();
}
 
void insertr(){
	int data;
	printf("Enter the data to enqueue:");
	scanf("%d",&data);
	Q *newnode=(Q*)malloc(sizeof(Q));
	if (rear==NULL){
		front=rear=newnode;
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else{
		rear->next=newnode;
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=rear;
		rear=newnode;
	}
	display();
}
 
void deletef(){
	Q *d;
	if (front==NULL){
		printf("Queue empty\n");
	}
	else if (front==rear){
		d=front;
		front=rear=NULL;
		printf("Dequeued element:%d\n",d->data);
		free(d);
		display();
	}
	else{
		d=front;
		front=front->next;
		front->prev=NULL;
		printf("Dequeued element:%d\n",d->data);
		free(d);
		display();
	}
}
 
void deleter(){
	Q *d;
	if (rear==NULL){
		printf("Queue empty\n");
	}
	else if (front==rear){
		d=rear;
		front=rear=NULL;
		printf("Dequeued element:%d\n",d->data);
		free(d);
		display();
	}
	else{
		d=rear;
		rear=rear->prev;
		rear->next=NULL;
		printf("Dequeued element:%d\n",d->data);
		free(d);
		display();
	}	
}
 
void main(){
	int c;
	do{
	printf("MENU\n1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue at front\n4.Dequeue at rear\n5.Display\n6.Exit\nEnter your choice:");
	scanf("%d",&c);
	switch (c){
		case 1:{
		insertf();
		break;}
		case 2:{
		insertr();
		break;}
		case 3:{
		deletef();
		break;}
		case 4:{
		deleter();
		break;}
		case 5:{
		display();
		break;}
		case 6:{
		printf("Exiting the pgm..\n");
		break;}
	}
	}while(c!=6);
}