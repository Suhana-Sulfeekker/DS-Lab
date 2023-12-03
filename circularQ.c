#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	struct nd*prev;
	int data;
	struct nd* next;
}node;
 
node *head=NULL;
 
void display(){
	node *temp=head;
	node *temp1;
	if (temp==NULL)
		printf("Circular linked list empty.\n");
	else{
	temp1=temp;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=temp1);
	printf("\n");}
}
 
void insert(){
	int data;
	printf("Enter the data to be inserted:");
	scanf("%d",&data);
	node *newnode=(node*)malloc(sizeof(node));
	if (head==NULL){
		head=newnode;
		newnode->data=data;
		newnode->next=head;
		newnode->prev=head;
	}
	else{
		node *temp;
		temp=head->prev;
		temp->next=newnode;
		newnode->data=data;
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=temp;		
	}
	display();
}
 
void delete(){
	if  (head==NULL){
		printf("List Empty\n");
		return;
	}
	int key;
	printf("Enter the data of node to be deleted:");
	scanf("%d",&key);
	node *temp=head;
	node *temp1=temp;
	int flag=0;
	do{
		if ((temp->data)==key){
		flag=1;
			if (head->next==head){
				node *d=head;
				head=NULL;
				free(d);
				display();
				break;
 
			}
			else if (temp==head && temp->next!=head){
				node *d=temp;
				head=head->next;
				(d->prev)->next=d->next;
				(d->next)->prev=d->prev;
				printf("Deleted element:%d\n",d->data);
				free(d);
				display();
				break;
			}
			else{
				node *d=temp;
				(temp->prev)->next=temp->next;
				(temp->next)->prev=d->prev;
				printf("Deleted element:%d\n",d->data);
				free(d);
				display();
				break;
			}
 
		}
		temp=temp->next;		
	}
	while(temp!=temp1);
	if (flag==0)
		printf("Key element not found\n");
}
 
void main(){
	int c;
	do{
	printf("MENU\n1.Insert\n2.Delete\n3.Exit\nEnter your choice:");
	scanf("%d",&c);
	switch (c){
		case 1:{
		insert();
		break;}
		case 2:{
		delete();
		break;}
		case 3:{
		printf("Exiting the pgm..\n");
		break;}
	}
	}while(c!=3);
}