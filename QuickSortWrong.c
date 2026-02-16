#include <stdio.h>
#include <stdlib.h>

int partitionFunc(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (pivot>=arr[i]);
        do
        {
            j--;
        } while (pivot<arr[j]);

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = pivot;
    pivot = arr[j];
    arr[j] = temp;
    return j;
};

void QuickSort(int *arr, int l, int h)
{
    if (l > h)
    {
        return;
    }
    int j = partitionFunc(arr, l, h);
    QuickSort(arr, l, j);
    QuickSort(arr, j + 1, h);
};

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
};

int main()
{
    printf("Enter the number of elements into the array: \n");
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n The array before Sorting using Quick Sort is \n");
    print(arr, n);
    QuickSort(arr, 0, n);
    printf("\n The array after Sorting using Quick Sort is \n");
    print(arr, n);
};