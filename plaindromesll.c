#include <stdio.h>
#include <stdlib.h>
 
typedef struct nd{
	struct nd* prev;
	char data;
	struct nd* next;
}node;
 
node *head=NULL,*rear=NULL;
 
void display(){
	node *temp=head;
	while (temp!=NULL){
		printf("%c ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
 
void DLL(char c){
	node *newnode=(node*)malloc(sizeof(node));
	if (head==NULL){
		head=rear=newnode;
		newnode->data=c;
		newnode->prev=NULL;
		newnode->next=NULL;		
	}
	else{
		rear->next=newnode;
		newnode->data=c;
		newnode->prev=rear;
		newnode->next=NULL;
		rear=rear->next;
	}	
}
 
void insert(){
	char s[100];
	printf("Enter the string:");
	scanf("%[^\n]",s);
	for(int i=0;s[i]!='\0';i++){
		DLL(s[i]);
	}
	display();
}
 
void palindrome(){
	printf("Checking whether the String is a plaindrome..\n");
	node *i,*j;
	j=rear;
	i=head;
	int flag=1;
	while(i!=j){
		if(i->data!=j->data){
		flag=0;
		printf("Not a palindrome.\n");
		break;
		}
		i=i->next;
		j=j->prev;
	}	
	if (flag==1)
		printf("YES,It is a plaindrome.\n");	
}
 
void main(){
	printf("Reading String..\n");
	insert();
	palindrome();
}