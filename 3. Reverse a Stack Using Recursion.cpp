//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

// Function to push an element
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
    }
}

// Function to pop an element
int pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to insert an element at the bottom of stack
void insertAtBottom(int item) {
    if (top == -1) {
        push(item);
    } else {
        int temp = pop();
        insertAtBottom(item);
        push(temp);
    }
}

// Function to reverse the stack using recursion
void reverse() {
    if (top != -1) {
        int temp = pop();
        reverse();
        insertAtBottom(temp);
    }
}

// Function to display stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("\nOriginal Stack:\n");
    display();

    reverse();

    printf("\nReversed Stack:\n");
    display();

    return 0;
}

