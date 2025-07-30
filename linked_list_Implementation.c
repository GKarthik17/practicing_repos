#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* nxtaddress;
} Node;

Node* temp = NULL;

Node* createnode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->nxtaddress = NULL;
    return newnode;
}

void insert_at_beggining(Node** head, int data)
{
    Node* new = createnode(data);
    new->nxtaddress = *head;
    *head = new;
    return;
}

void insert_at_end(Node** head, int data)
{
    Node* new = createnode(data);
    if(*head == NULL){
        *head = new;
        temp = new;
    }else {
        temp->nxtaddress = new;
        temp = new;
    }
    return;
}

void deleteFromFirst(Node** head){
    if(*head == NULL){
        return;
    }
    Node* current = *head;
    *head = current->nxtaddress;
    free(current);
    return;
}

void deleteFromEnd(Node** head)
{
    Node* current = *head;
    while (current->nxtaddress->nxtaddress != NULL) {
        current = current->nxtaddress;
    }
    free(current->nxtaddress);
    current->nxtaddress = NULL;
}

void print_linkedlist(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        printf("[ %d ] -> ", current->data);
        current = current->nxtaddress;
    }
    printf("NULL\n");
    return;
}


int main() {
    Node* head = NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 10);
    insert_at_end(&head, 10);
    insert_at_beggining(&head, 5);
    deleteFromEnd(&head);
    deleteFromFirst(&head);
    print_linkedlist(head);
    return 0;
}
