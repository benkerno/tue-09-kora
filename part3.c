// part3_linked_lists.c
// This program was written by Sofia De Bellis (z5418801) and YOUR-NAME (zID)
// Program tests linked lists functions

#include <stdio.h>
#include <stdlib.h>


struct node {
    // The data stored in the node
    int data;
    // Pointer to the next node in the linked list
    struct node *next;
};

void free_list(struct node *head);

struct node *create_node(int data);

struct node *insert_head(struct node *head, int data);

struct node *insert_tail(struct node *head, int data);

void print_list(struct node *head);

int list_length(struct node *head);

int main(void) {

    // Create a pointer to the head of the linked list
    struct node *head = NULL;

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 10);

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 5);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 15);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 20);

    // Print the linked list
    print_list(head);

    // Calculate and print the length of the linked list
    int length = list_length(head);
    printf("There are %d nodes in the list\n", length);
    free_list(head);
    return 0;
}

// Creates a new node
//
// Parameters:
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new node
struct node *create_node(int data) {
    // TODO
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
    // exit(1);
}

// Inserts a new node at the head of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new head of the linked list
struct node *insert_head(struct node *head, int data) {
    struct node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
    // exit(1);
}

// Inserts a new node at the tail of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the head of the linked list
struct node *insert_tail(struct node *head, int data) {
    struct node *new_node = create_node(data);

    struct node *curr = head;
    if (head->next == NULL) {
        return new_node;
    }

    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    return head;
}

// Traverses a linked list and prints the data in each node
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      None
void print_list(struct node *head) {
    // Set current to be the first node in the list
    struct node *current = head;
    
    // Traverse the linked list and print each node 
    // until we reach the end of the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("X\n");
}


// Finds the number of nodes in a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      The number of nodes in the linked list
int list_length(struct node *head) {
    // TODO

    int count = 0;
    if (head == NULL ) {
        return count;
    }

    struct node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void free_list(struct node *head) {
    struct node *curr = head;
    struct node *prev = head;

    if (head == NULL) {
        return;
    }

    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }


}
