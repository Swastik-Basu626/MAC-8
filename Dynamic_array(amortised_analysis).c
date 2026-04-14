#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 1;
    int size = 0;
    int *arr = (int*)malloc(capacity * sizeof(int));

    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        if (size == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
        }

        arr[size++] = value;
    }

    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}