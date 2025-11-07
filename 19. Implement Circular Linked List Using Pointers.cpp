//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void display() {
    if (last == NULL) {
        printf("Circular List is empty!\n");
        return;
    }
    struct Node* temp = last->next;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert End\n2. Display\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

