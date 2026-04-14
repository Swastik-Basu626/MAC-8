#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < right && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (left < right && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
    }

    heapify(arr, n, i);
}
int main()
{
    int n;
    printf("Enter the number of array elements\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("\nEnter the elements into the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    HeapSort(arr, n);

    printf("\nArray after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}