//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

#define MAX 2   // Max keys in a node (order-1)
#define MIN 1   // Min keys in a node

// B-tree node structure
typedef struct BTreeNode {
    int keys[MAX];
    struct BTreeNode *child[MAX + 1];
    int n;        // current number of keys
    int leaf;     // 1 if leaf, 0 otherwise
} BTreeNode;

// Create a new node
BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < MAX + 1; i++)
        node->child[i] = NULL;
    return node;
}

// Traverse B-tree (inorder)
void traverse(BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->child[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->child[root->n]);
    }
}

// Split child
void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
    BTreeNode* z = createNode(child->leaf);
    z->n = MIN;  // MIN = ceil(MAX/2)-1 = 1

    // Copy last key to z
    z->keys[0] = child->keys[2];  // 3 keys, index 2

    // Copy child pointers if not leaf
    if (!child->leaf) {
        z->child[0] = child->child[2];
        z->child[1] = child->child[3];
    }

    child->n = MIN;  // first key remains

    // Shift parent's children to make space
    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];

    parent->child[i + 1] = z;

    // Shift parent's keys to make space
    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    // Move middle key to parent
    parent->keys[i] = child->keys[1];
    parent->n += 1;
}

// Insert non-full node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        // Shift keys to insert new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n += 1;
    } else {
        // Find child to descend
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;
        if (node->child[i]->n == MAX)
            splitChild(node, i, node->child[i]);
        insertNonFull(node->child[i], key);
    }
}

// Insert key into B-tree
BTreeNode* insert(BTreeNode* root, int key) {
    if (root == NULL)
        return createNode(1);

    if (root->n == MAX) {
        BTreeNode* s = createNode(0);
        s->child[0] = root;
        splitChild(s, 0, root);
        insertNonFull(s, key);
        return s;  // new root
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Main function
int main() {
    BTreeNode* root = NULL;
    int n, val;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal of B-Tree: ");
    traverse(root);
    printf("\n");

    return 0;
}

