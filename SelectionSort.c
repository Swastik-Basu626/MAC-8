#include <stdio.h>
#include <stdlib.h>
static int count = 0;
void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        count++;
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                count++;
                min = j;
            }
        }
        count += 3;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements into the array :\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements into the array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting :\n");
    printArray(arr, n);
    SelectionSort(arr, n);
    printf("\nArray after sorting :\n");
    printArray(arr, n);
    printf("\nThe number of operations performed by the selection sort algorithm is : %d\n", count);
    free(arr);
    return 0;
}