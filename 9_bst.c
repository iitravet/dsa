#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int key) {
    if (!root) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (root->data < key) return search(root->right, key);
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    if(search(root, 30)) printf("Found 30\n");
    return 0;
}
