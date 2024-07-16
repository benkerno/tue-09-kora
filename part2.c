#include <stdio.h>

struct node {
    int data;
    struct node *next;
}

int main(void) {
    struct node* head;

    //node 1
    struct node* n1 = malloc(sizeof(struct node));
    n1->next = NULL;
    n1->data = 3;

    head = n1;

    //node2
    struct node* n2 = malloc(sizeof(struct node));
    n2->next = NULL;
    n2->data = 9;

    n1->next = n2;

      //node3
    struct node* n3 = malloc(sizeof(struct node));
    n3->next = NULL;
    n3->data = 5;

    n3->next = n1;
    head = n3;

}
