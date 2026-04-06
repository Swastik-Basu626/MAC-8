#include <stdio.h>
#include <stdlib.h>
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int temp[10] = {0};
    int *output = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        temp[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        temp[i] += temp[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[temp[digit] - 1] = arr[i];
        temp[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(output);
}
void Radix_Sort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int i = 1; max / i > 0; i *= 10)
    {
        countSort(arr, n, i);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements into the array");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    Radix_Sort(arr, n);
    printf("\nArray after sorting is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}