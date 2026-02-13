#include <stdio.h>
#include <stdlib.h>
static int count =0; 
void BubbleSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        count++;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                count+=3;
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
};

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements into the array :\n");
    scanf("%d", &n);
    int *arr= (int*)malloc(n*sizeof(int));
    printf("Enter the elements into the array :\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting :\n");
    printArray(arr, n);
    BubbleSort(arr, n);
    printf("\nArray after sorting :\n");
    printArray(arr, n);
    printf("\nThe number of operations performed by the bubble sort algorithm is : %d\n", count);
    free(arr);
    return 0;
}