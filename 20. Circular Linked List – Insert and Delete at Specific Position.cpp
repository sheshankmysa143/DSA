//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertAtPosition(int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        if (pos != 1) {
            printf("Invalid position!\n");
            return;
        }
        last = newNode;
        last->next = last;
        return;
    }

    struct Node* temp = last->next;
    if (pos == 1) {
        newNode->next = temp;
        last->next = newNode;
        return;
    }

    for (int i = 1; i < pos - 1 && temp != last; i++) {
        temp = temp->next;
    }
    if (temp == last && pos > 2) {
        printf("Position out of range!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) last = newNode;
}

void deleteAtPosition(int pos) {
    if (last == NULL) {
        printf("List empty!\n");
        return;
    }
    struct Node* temp = last->next;
    if (pos == 1) {
        if (last->next == last) {
            free(last);
            last = NULL;
        } else {
            last->next = temp->next;
            free(temp);
        }
        return;
    }
    for (int i = 1; i < pos - 1 && temp->next != last->next; i++) {
        temp = temp->next;
    }
    if (temp->next == last->next) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    if (del == last) last = temp;
    free(del);
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
    int choice, val, pos;
    while (1) {
        printf("\n--- Circular Linked List Insert/Delete ---\n");
        printf("1. Insert at Position\n2. Delete at Position\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPosition(val, pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

