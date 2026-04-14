#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Enter the value of n\n");
    int n;
    scanf("%d", &n);
    printf("series upto n is \n");
    int a = 0;
    int b = 1;
    printf("%d ", a);
    printf("%d ", b);
    for (int i = 1; i < n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}