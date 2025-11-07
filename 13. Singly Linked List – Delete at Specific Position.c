//CH.SC.U4CSE24125
//SHESHANK.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
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

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    // Display before deletion
    temp = head;
    printf("Linked list before deletion: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Deletion
    struct node *todelete;
    printf("Enter the deleted position\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    if (pos == 1) {
        todelete = head;
        head = head->next; // fix
        free(todelete);
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++) { // fix
            temp = temp->next;
        }
        todelete = temp->next;
        temp->next = todelete->next; // fix
        free(todelete); // free memory
    }

    // Display after deletion
    temp = head;
    printf("Linked list after deletion: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

