#include <stdio.h>
#include <stdlib.h>
static int count = 0;
void InsertionSort(int *arr, int n){
    for(int i=1;i<n;i++){
        int keys = arr[i];
        int prev = i-1;
        count+=2;
        while(prev>=0 && arr[prev]>keys){
            count+=2;
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=keys;
        count++;
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
    InsertionSort(arr, n);
    printf("\nArray after sorting :\n");
    printArray(arr, n);
    printf("\nThe number of operations performed by the insertion sort algorithm is : %d\n", count);
    free(arr);
    return 0;
}