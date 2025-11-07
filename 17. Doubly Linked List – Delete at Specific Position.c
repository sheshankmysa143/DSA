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
    struct node *temp = NULL, *head = NULL;
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

    // Deletion
    printf("Enter position to delete\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    if (pos == 1) { // Delete head
        temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
    } else {
        temp = head;
        for (i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return 1;
        }
        if (temp->prev != NULL) temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;
        free(temp);
    }

    // Display after deletion
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

