//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element arr[MAX];
    int size;
} PriorityQueue;

// Function to initialize queue
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to check if queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Function to check if queue is full
int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

// Insert element based on priority
void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Queue is full! Cannot insert.\n");
        return;
    }

    int i = pq->size - 1;
    // Shift elements to keep array sorted by priority
    while (i >= 0 && pq->arr[i].priority < priority) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }
    pq->arr[i + 1].data = value;
    pq->arr[i + 1].priority = priority;
    pq->size++;
}

// Remove highest priority element
int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = pq->arr[0].data;
    // Shift elements left
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
    return value;
}

// Peek highest priority element
int peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pq->arr[0].data;
}

// Display queue
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d | Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 5, 1);
    enqueue(&pq, 20, 3);
    enqueue(&pq, 15, 2);

    display(&pq);

    printf("\nDequeued: %d\n", dequeue(&pq));
    printf("Front element (peek): %d\n", peek(&pq));

    printf("\nAfter Dequeue:\n");
    display(&pq);

    return 0;
}

