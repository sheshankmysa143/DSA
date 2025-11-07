#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int height(struct Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }

struct Node* newNode(int key) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* insert(struct Node* n, int key) {
    if (!n) return newNode(key);
    if (key < n->key) n->left = insert(n->left, key);
    else if (key > n->key) n->right = insert(n->right, key);
    else return n;

    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);

    if (b > 1 && key < n->left->key) return rightRotate(n);
    if (b < -1 && key > n->right->key) return leftRotate(n);
    if (b > 1 && key > n->left->key) { n->left = leftRotate(n->left); return rightRotate(n); }
    if (b < -1 && key < n->right->key) { n->right = rightRotate(n->right); return leftRotate(n); }

    return n;
}

struct Node* minNode(struct Node* n) {
    while (n->left) n = n->left;
    return n;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            struct Node* temp = root->left ? root->left : root->right;
            if (!temp) { temp = root; root = NULL; }
            else *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int b = getBalance(root);

    if (b > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (b > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (b < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (b < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }

    return root;
}

void preOrder(struct Node* root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder before deletion:\n");
    preOrder(root);

    root = deleteNode(root, 40);
    printf("\nPreorder after deleting 40:\n");
    preOrder(root);
}

