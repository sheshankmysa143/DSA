//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int val) {
    stack1[++top1] = val;
}

int pop1() {
    return stack1[top1--];
}

void push2(int val) {
    stack2[++top2] = val;
}

int pop2() {
    return stack2[top2--];
}

void enqueue(int val) {
    push1(val);
    printf("%d enqueued\n", val);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    return pop2();
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1) printf("Dequeued: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

