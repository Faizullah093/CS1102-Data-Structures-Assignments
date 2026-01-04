#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Sona ekleme (Cembersel)
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    
    temp->next = newNode;
    newNode->next = *head;
}

// Listeleme (Traversal)
void display(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Bas)\n");
}

// Silme islemi (Cembersel)
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;
    struct Node *curr = *head, *prev;
    
    // Bas düğümü silme durumu
    if (curr->data == key) {
        struct Node* last = *head;
        while (last->next != *head) last = last->next;
        if (curr->next == *head) { // Listede tek eleman varsa
            free(curr);
            *head = NULL;
        } else {
            last->next = curr->next;
            *head = curr->next;
            free(curr);
        }
        return;
    }
    
    while (curr->next != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    display(head);
    
    printf("1 siliniyor...\n");
    deleteNode(&head, 1);
    display(head);
    
    return 0;
}