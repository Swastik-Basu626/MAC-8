#include<stdio.h>
#include<stdlib.h>
static int countsteps=0;
int max(int arr[], int n)
{
    int maxVal = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void CountSort(int arr[], int n){
    
    int maxVal = max(arr, n);

    int *count = calloc(maxVal + 1, sizeof(int));

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for(int i = 1; i <= maxVal; i++){
        count[i] += count[i-1];
    }
    int *output = malloc(sizeof(int) * n);

    for(int i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        countsteps++;
    }

    // Step 4: Print sorted array
    for(int i = 0; i < n; i++){
        printf("%d ", output[i]);
    }

}

int main()
{
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    CountSort(arr, n);
    printf("\n Total no. of steps performed is:- %d\n", countsteps);
}