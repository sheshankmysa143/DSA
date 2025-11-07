//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>
#define MAX 5  // maximum stack size

int main() {
    int stack[MAX], top = -1;
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Push
            if (top == MAX - 1) {
                printf("Stack Overflow! Cannot push.\n");
            } else {
                printf("Enter value to push: ");
                scanf("%d", &value);
                top++;
                stack[top] = value;
                printf("Pushed %d\n", value);
            }
            break;

        case 2: // Pop
            if (top == -1) {
                printf("Stack Underflow! Cannot pop.\n");
            } else {
                printf("Popped %d\n", stack[top]);
                top--;
            }
            break;

        case 3: // Display
            if (top == -1) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack elements: ");
                for (int i = top; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

