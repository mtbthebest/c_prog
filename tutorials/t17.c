//
// Created by mtb on 8/15/22.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"


typedef struct LinkedList LinkedList ;
struct LinkedList{
        int data;
        LinkedList *next;
};

LinkedList *build_list(LinkedList *h, int value){
    LinkedList *n =(LinkedList *) malloc(sizeof(*h));
    n->data = value;
    h->next = n;
    n->next = NULL;
    return n;
}

void cleanup(LinkedList *head){
    head = head->next;
    while (head){
        LinkedList *h = head->next;
        free(head);
        head = h;

    }
    puts(" ");
    puts("Linked list has been cleaned");
}

_Bool find(LinkedList *head, int value){
    while(head != NULL && head->data != value){
        head = head->next;
    }

    return head != NULL;
}

void display(LinkedList *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void fn1(){
    LinkedList *head;
    LinkedList h = {0, NULL};
    int s = 4;
    head = &h;
    time_t t = {4};
    srand(t);

    for(int i=1; i<s; i++){
        int j =(int ) ( (rand() / (double ) RAND_MAX) * 50);
        head = build_list(head, j);
        printf("%d ", j);
    }
    printf("\n");

    display(&h);
    _Bool g = find(&h, 6);
    puts("");
    printf("Find value 6 %d ", g);
    cleanup(&h);
}

int main(){

    fn1();

    return 0;
}
