#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	int data;
	struct nd* next;
}node;
node *head,*temp;
 
 
void displayList(){
	temp=head;
	if (head==NULL)
		printf("List Empty\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
 
void createList(int n){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	int data;
	printf("Enter data:");
	scanf("%d",&data);
	newnode->data=data;
	head=newnode;
	for(int i=1;i<n;i++){		
		newnode->next=(node*)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d",&data);
		newnode=newnode->next;
		newnode->data=data;
 
	}
	newnode->next=NULL;
	displayList();
}
 
void insertAfter(){
	int item,data;
	printf("Enter the data of node after which new node is to be entered:");
	scanf("%d",&item);
	printf("Enter data to be entered in newnode:");
	scanf("%d",&data);
	temp=head;
	while (temp->data!=item && temp!=NULL){
		temp=temp->next;
	}
	if (temp==NULL)
		printf("Item not found\n");
	else{
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->next=temp->next;
		temp->next=newnode;
	}
	displayList();
}
 
void insertBefore(){
	node *prev;
	int item,data;
	printf("Enter the data of node before which new node is to be entered:");
	scanf("%d",&item);
	printf("Enter data to be entered in newnode:");
	scanf("%d",&data);
	temp=head;
	while (temp->data!=item && temp!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if (temp==NULL)
		printf("Item not found\n");
	else{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->next=temp;
		if (temp==head){
			head=newnode;
		}
		else{
			prev->next=newnode;
		}
	}
	displayList();	
}
 
void insertPosition(){
	node *prev;
	int pos,data;
	printf("Enter the position for inserting newnode:");
	scanf("%d",&pos);
	printf("Enter the data to be entered:");
	scanf("%d",&data);
	temp=head;
	int count=0;
	while (temp!=NULL){
		count+=1;
		if (pos==count){
			node *newnode=(node*)malloc(sizeof(node));
			newnode->data=data;
			newnode->next=temp;
			if (temp==head)
				head=newnode;
			else
				prev->next=newnode;
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if (count!=pos)
		printf("List position out of bounds\n");
	displayList();
}
 
void deleteData(){
	node *prev=NULL;
	while (head==NULL)
		printf("List empty\n");
	int item;
	printf("Enter the data value whose node is to be deleted:");
	scanf("%d",&item);
	temp=head;
	while (temp!=NULL){
		if (temp->data==item){
			if(temp==head){
				head=temp->next;
				free(temp);
			}
			else{
				prev->next=temp->next;
				free(temp);
			}
            break;
		}        
		prev=temp;
		temp=temp->next;
	}
	if (temp==NULL)
		printf("Data item not found\n");
	displayList();
}
 
void deletePosition(){
	node *prev;
	int pos;
	printf("Enter the position for deleting node:");
	scanf("%d",&pos);
	temp=head;
	int count=0;
	while (temp!=NULL){
		count+=1;
		if (pos==count){
			if (temp==head){
				head=temp->next;
				free(temp);
			}
			else{
				prev->next=temp->next;
				free(temp);
			}
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if (count!=pos)
		printf("List position out of bounds\n");
	displayList();
}
 
int minElement(){
	temp=head;
	int min=temp->data;
	while(temp!=NULL){
		if (temp->data<min)
			min=temp->data;
		temp=temp->next;
	}
	printf("Minimum element:%d\n",min);
	return min;
}
 
void deletemin(int min){
	node *prev=NULL;
	temp=head;
	while (temp!=NULL){
		if (temp->data==min){
			if (temp==head){
				head=temp->next;
				free(temp);
			}
			else{
				prev->next=temp->next;
				free(temp);
			}
            break;
		}
		prev=temp;
		temp=temp->next;
	}
	displayList();
}
 
void searchElement(){
    int item,count=0;
    printf("Enter the item to be searched:");
    scanf("%d",&item);
    temp=head;
    while (temp!=NULL){
        count+=1;
        if (temp->data==item){
            printf("Item found at position %d\n",count);
        }
        temp=temp->next;
    }
    if (count==0)
        printf("Item not found\n");
}

void main(){
	int c1;
	do{
	printf("MENU\n1.Creation\n2.Insertion\n3.Deletion\n4.Search\n5.Display\n6.Exit\nEnter Choice:");
	scanf("%d",&c1);
	switch(c1){
		case 1:{
			int n;
			printf("Enter Number of Elements:");
			scanf("%d",&n);
			createList(n);
			break;
		}
		case 2:{
			int c2;
			printf("1.Insert new node after a given node data\n2.Insert new node before a given node data\n3.Insert a new node in the given position\nEnter Choice:");
			scanf("%d",&c2);
			switch(c2){
				case 1:{
					insertAfter();
					break;
				}
				case 2:{
					insertBefore();
					break;
				}
				case 3:{
					insertPosition();
					break;
				}
				default:break;
			}
			break;
		}
		case 3:{
			int c3;
			printf("1.Delete a node,given the key data value\n2.Delete a node, given the position\n3.Delete the smallest element from the list\nEnter your choice:");
			scanf("%d",&c3);
			switch(c3){
				case 1:{
					deleteData();
					break;
				}
				case 2:{
					deletePosition();
					break;
				}
				case 3:{
					int min=minElement();
					deletemin(min);
					break;
				}
				default:break;
			}
			break;
		}
		case 4:{
			searchElement();
			break;
		}
		case 5:{
			displayList();
			break;
		}
		default:break;
	}
	}
	while(c1 != 6);	
}