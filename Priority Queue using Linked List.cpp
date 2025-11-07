//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

Node* front = NULL;

// Create a new node
Node* createNode(int value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Enqueue with priority
void enqueue(int value, int priority) {
    Node* newNode = createNode(value, priority);

    // Insert at front if queue is empty or higher priority
    if (front == NULL || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Dequeue highest priority
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    free(temp);
    return value;
}

// Peek (get front element)
int peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Priority Queue (Linked List):\n");
    while (temp != NULL) {
        printf("Value: %d | Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    enqueue(10, 2);
    enqueue(5, 1);
    enqueue(20, 3);
    enqueue(15, 2);

    display();

    printf("\nDequeued: %d\n", dequeue());
    printf("Front element (peek): %d\n", peek());

    printf("\nAfter Dequeue:\n");
    display();

    return 0;
}

