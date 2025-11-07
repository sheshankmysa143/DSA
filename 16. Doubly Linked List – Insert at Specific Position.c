//CH.SC.U4CSE24125
//SHESHANK.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main() {
    struct node *temp = NULL;
    struct node *head = NULL;
    int i, value, n, pos;

    printf("Enter the size of linked list\n");
    scanf("%d", &n);
    printf("Enter elements\n");

    for (i = 0; i < n; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Display forward
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Insertion
    printf("Enter position\n");
    scanf("%d", &pos);
    printf("Enter the value which should be inserted\n");
    scanf("%d", &value);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 1;
    }

    if (pos == 1) { // Insert at head
        newnode->next = head;
        if (head != NULL) head->prev = newnode;
        head = newnode;
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return 1;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }

    // Display after insertion
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

