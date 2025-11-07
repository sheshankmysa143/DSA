#include <stdio.h>
int main()
{
    int n, i, data, mid, low, high;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &data);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == data) {
            printf("Element found at index %d\n", mid);
            break;
        }
        else if (arr[mid] < data) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (low > high) {
        printf("Element not found\n");
    }
    return 0;
}

