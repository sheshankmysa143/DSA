//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 6
#define P 0.5

// Node structure
typedef struct Node {
    int key;
    struct Node* forward[MAX_LEVEL + 1];  // pointers for each level
} Node;

typedef struct SkipList {
    Node* header;
    int level;
} SkipList;

// Function to create a new node
Node* createNode(int key, int level) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    for (int i = 0; i <= MAX_LEVEL; i++)
        node->forward[i] = NULL;
    return node;
}

// Initialize skip list
SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(INT_MIN, MAX_LEVEL);
    return list;
}

// Generate random level
int randomLevel() {
    int lvl = 0;
    while ((rand() % 100) < (P * 100) && lvl < MAX_LEVEL)
        lvl++;
    return lvl;
}

// Search key
Node* search(SkipList* list, int key) {
    Node* current = list->header;
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != NULL && current->key == key)
        return current;
    return NULL;
}

// Insert key
void insert(SkipList* list, int key) {
    Node* update[MAX_LEVEL + 1];
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current == NULL || current->key != key) {
        int lvl = randomLevel();
        if (lvl > list->level) {
            for (int i = list->level + 1; i <= lvl; i++)
                update[i] = list->header;
            list->level = lvl;
        }

        Node* newNode = createNode(key, lvl);
        for (int i = 0; i <= lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        printf("Inserted: %d\n", key);
    }
}

// Delete key
void deleteKey(SkipList* list, int key) {
    Node* update[MAX_LEVEL + 1];
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL && current->key == key) {
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        free(current);

        while (list->level > 0 && list->header->forward[list->level] == NULL)
            list->level--;

        printf("Deleted: %d\n", key);
    } else {
        printf("Key not found: %d\n", key);
    }
}

// Display skip list
void display(SkipList* list) {
    printf("\nSkip List:\n");
    for (int i = list->level; i >= 0; i--) {
        Node* node = list->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("%d ", node->key);
            node = node->forward[i];
        }
        printf("\n");
    }
}

int main() {
    SkipList* list = createSkipList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 30);
    insert(list, 15);

    display(list);

    Node* found = search(list, 20);
    if (found)
        printf("Found: %d\n", found->key);
    else
        printf("Not Found\n");

    deleteKey(list, 20);
    display(list);

    return 0;
}

