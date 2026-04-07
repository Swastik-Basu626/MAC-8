#include <stdio.h>
#include <stdlib.h>
#define BUCKETS 10

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > key)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = key;
    }
}

void BucketSort(float arr[], int n)
{
    float *buckets[BUCKETS];
    int count[BUCKETS] = {0};

    for (int i = 0; i < BUCKETS; i++)
    {
        buckets[i] = (float *)malloc(sizeof(float) * n);
    }

    for (int i = 0; i < n; i++)
    {
        int position = (int)(BUCKETS * arr[i]);
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
}
int main()
{
    int n;
    printf("Enter the number of elements into the array\n");
    scanf("%d", &n);
    printf("\nEnter the elements in the array from range 0 to 1\n");
    float *arr = (float *)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("\nArray before sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    BucketSort(arr, n);

    printf("\nArray after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
}