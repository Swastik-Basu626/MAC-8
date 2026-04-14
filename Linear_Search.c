#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the value of n");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched\n");
    int key;
    scanf("%d", &key);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("Element found at index %d ", i+1);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("element not found");
    }
}