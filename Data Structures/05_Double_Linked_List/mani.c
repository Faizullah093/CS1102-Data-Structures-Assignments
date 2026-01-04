#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Sona ekleme
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* last = *head;
    while (last->next != NULL) last = last->next;
    
    last->next = newNode;
    newNode->prev = last;
}

// Silme işlemi
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    
    if (temp == NULL) return; // Bulunamadi
    
    if (*head == temp) *head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
}

// Listeleme (Traversal)
void display(struct Node* node) {
    printf("Liste: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);
    
    printf("20 siliniyor...\n");
    deleteNode(&head, 20);
    display(head);
    
    return 0;
}