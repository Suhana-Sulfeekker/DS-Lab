#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int coeff;
    int exp;
    struct nd* next;
} poly;

void display(poly* head) {
    poly* temp;
    temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf("+");
        temp = temp->next;
    }
    printf("\n");
}

void readpoly(poly** head) {
    int c, e, f;
    poly* temp = NULL;
    do {
        printf("Enter coeff:");
        scanf("%d", &c);
        printf("Enter exp:");
        scanf("%d", &e);
        poly* newnode = (poly*)malloc(sizeof(poly));
        newnode->coeff = c;
        newnode->exp = e;
        newnode->next = NULL;
        if (*head == NULL) {
            *head = newnode;
            temp = *head;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }
        printf("Are there more terms?");
        scanf("%d", &f);
    } while (f == 1);
    display(*head);
}

void addpoly(poly* ahead, poly* bhead, poly** rhead) {
    poly* temp = NULL;
    while (ahead && bhead) {
        poly* newnode = (poly*)malloc(sizeof(poly));
        if (ahead->exp > bhead->exp) {
            newnode->coeff = ahead->coeff;
            newnode->exp = ahead->exp;
            ahead = ahead->next;
        }
        else if (ahead->exp < bhead->exp) {
            newnode->coeff = bhead->coeff;
            newnode->exp = bhead->exp;
            bhead = bhead->next;
        }
        else {
            newnode->coeff = ahead->coeff + bhead->coeff;
            newnode->exp = ahead->exp;
            ahead = ahead->next;
            bhead = bhead->next;
        }
        newnode->next = NULL;
        if (*rhead == NULL) {
            *rhead = newnode;
            temp = *rhead;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    if (ahead){
        poly* newnode = (poly*)malloc(sizeof(poly));
        while (ahead!=NULL){
            newnode->coeff = ahead->coeff;
            newnode->exp = ahead->exp;
            ahead = ahead->next;
            if (*rhead == NULL) {
                *rhead = newnode;
                temp = *rhead;
            }
            else {
                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
    if (bhead){
        poly* newnode = (poly*)malloc(sizeof(poly));
        while (bhead!=NULL){
            newnode->coeff =bhead->coeff;
            newnode->exp=bhead->exp;
            bhead = bhead ->next;
            if (*rhead == NULL) {
                *rhead = newnode;
                temp = *rhead;
            }
            else {
                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
    display(*rhead);
}

void main() {
    poly* ahead = NULL;
    poly* bhead = NULL;
    poly* rhead = NULL;

    printf("Reading polynomial A..\n");
    readpoly(&ahead);
    printf("Reading polynomial B..\n");
    readpoly(&bhead);
    printf("Adding A+B..\n");
    addpoly(ahead, bhead, &rhead);
}
