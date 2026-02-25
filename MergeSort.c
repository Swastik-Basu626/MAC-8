#include <stdio.h>
#include <stdlib.h>

static int count=0;
void merge(int arr[], int low, int mid, int high)
{
    int lhs = mid - low + 1;
    int rhs = high - mid;
    int leftArray[lhs];
    int rightArray[rhs];
    for (int i = 0; i < lhs; i++)
    {
        leftArray[i] = arr[low + i];
    }
    for (int i = 0; i < rhs; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < lhs && j < rhs)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            count++;
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            count++;
            j++;
        }
        count++;
        k++;
    }
    for (; i < lhs; i++)
    {
        arr[k] = leftArray[i];
        k++;
        count++;
    }

    for (; j < rhs; j++)
    {
        arr[k] = rightArray[j];
        k++;
        count++;
    }
};
void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
};
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    printf("Enter the number of elements into the array\n");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements into the array\n");
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting :\n");
    printArray(arr, n);
    MergeSort(arr, 0, n-1);
    printf("\nArray after sorting :\n");
    printArray(arr, n);
    printf("\nThe number of operations performed by the insertion sort algorithm is : %d\n", count);
    free(arr);
    return 0;
}