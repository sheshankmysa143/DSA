//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue1[MAX], queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int val) {
    if (rear1 == MAX - 1) {
        printf("Queue1 Overflow!\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    queue1[++rear1] = val;
}

int dequeue1() {
    if (front1 == -1) return -1;
    int val = queue1[front1];
    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
        front1++;
    }
    return val;
}

void enqueue2(int val) {
    if (rear2 == MAX - 1) {
        printf("Queue2 Overflow!\n");
        return;
    }
    if (front2 == -1) front2 = 0;
    queue2[++rear2] = val;
}

int dequeue2() {
    if (front2 == -1) return -1;
    int val = queue2[front2];
    if (front2 == rear2) {
        front2 = rear2 = -1;
    } else {
        front2++;
    }
    return val;
}

void push(int val) {
    enqueue2(val);
    while (front1 != -1) {
        enqueue2(dequeue1());
    }
    // swap queues
    int f, r, *q;
    f = front1; r = rear1; q = queue1;
    front1 = front2; rear1 = rear2; queue1[0] = queue2[0];
    front2 = f; rear2 = r; queue2[0] = q[0];
}

int pop() {
    if (front1 == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue1();
}

void display() {
    if (front1 == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Using Queue ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) printf("Popped: %d\n", val);
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

