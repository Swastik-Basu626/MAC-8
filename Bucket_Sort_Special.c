#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

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

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int keys = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > keys)
        {

            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = keys;
    }
}
void BucketSort(int arr[], int n)
{
    int *buckets[BUCKETS];
    int count[BUCKETS] = {0};

    for (int i = 0; i < BUCKETS; i++)
    {
        buckets[i] = (int *)malloc(sizeof(int) * n);
    }

    int max = getMax(arr, n);

    for (int i = 0; i < n; i++)
    {
        int position = (arr[i] * BUCKETS) / (max + 1);
        buckets[position][count[position]++] = arr[i];
    }

    for (int i = 0; i < BUCKETS; i++)
    {
        insertionSort(buckets[i], count[i]);
    }

    int k = 0;
    for (int i = 0; i < BUCKETS; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < BUCKETS; i++)
    {
        free(buckets[i]);
    }
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

    BucketSort(arr, n);

    printf("\nArray after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}