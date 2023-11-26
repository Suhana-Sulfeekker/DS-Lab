#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int data;
    struct nd* next;
}node;

node *head,*temp;

int  displayList(){
	temp=head;
	if (head==NULL)
		printf("List Empty\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
    return 0;
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

void reverseList(){
    displayList();
}


void sortList(){
    if (head == NULL || head->next == NULL) {
        displayList();
        return;
    }
    int count = 0;
    node *t1, *t2, *t3, *p, *prev;
    temp = head;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    for (int i = 0; i < count - 1; i++) {
        t1 = NULL;
        t2 = head;
        t3 = head->next;
        p = NULL;
        prev = NULL;
        for (int j = 0; j < count - 1 - i; j++) {
            if (t2->data > t3->data) {
                if (t1 != NULL) {
                    t1->next = t3;
                }
                else {
                    head = t3;
                }
                t2->next = t3->next;
                t3->next = t2;               
                p = t3;
                t3 = t2->next;
            } 
            else {
                p = t2;
                t2 = t3;
                t3 = t3->next;
            }
        }
    }
    displayList();
}


void main()
{
    int c1;
    do{
        printf("MENU\n1.Create List\n2.Reverse List\n3.Sort List\n4.Exit\nEnter your choice:");
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
                reverseList();
                break;
            }
            case 3:{
                sortList();
                break;
            }
            case 4:{
                printf("Exiting List....\n");
                break;
            }
            default: break;
        }
    }
    while(c1!=4);
}