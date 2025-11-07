//CH.SC.U4CSE24125
//SHESHANK.

#include <stdio.h>

int main()
{
    int n, i, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &data);

    for (i = 0; i < n; i++) {
        if (arr[i] == data) {
            printf("Element found at index %d\n", i);
            break;
        }
    }

    if (i == n) {
        printf("Element not found\n");
    }

    return 0;
}

