//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into Min-Heap
void insert(int value) {
    if (size >= MAX - 1) {
        printf("Heap is full!\n");
        return;
    }

    size++;
    heap[size] = value;   // Place at last position
    int i = size;

    // Heapify upwards
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
    printf("Inserted %d\n", value);
}

// Delete root (min element)
int deleteMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int min = heap[1];
    heap[1] = heap[size]; // Move last to root
    size--;

    int i = 1;

    // Heapify downwards
    while (i * 2 <= size) {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left <= size && heap[left] < heap[smallest])
            smallest = left;
        if (right <= size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return min;
}

// Display heap
void display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Min-Heap: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);

    display();

    printf("Deleted Min: %d\n", deleteMin());
    display();

    printf("Deleted Min: %d\n", deleteMin());
    display();

    return 0;
}

