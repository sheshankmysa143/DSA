//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* minNode(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* delete(struct Node* root, int val) {
    if (!root) return root;
    if (val < root->data) root->left = delete(root->left, val);
    else if (val > root->data) root->right = delete(root->right, val);
    else {
        if (!root->left) { struct Node* t = root->right; free(root); return t; }
        else if (!root->right) { struct Node* t = root->left; free(root); return t; }
        struct Node* t = minNode(root->right);
        root->data = t->data;
        root->right = delete(root->right, t->data);
    }
    return root;
}

void inorder(struct Node* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display (Inorder)\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

