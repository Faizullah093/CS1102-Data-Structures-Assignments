#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Diziden agac olusturma (Level Order)
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n) {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

// Agaci test etmek icin Inorder gezinti
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    
    printf("Olusturulan Agacin Inorder Gezintisi: ");
    inOrder(root);
    printf("\n");
    
    return 0;
}