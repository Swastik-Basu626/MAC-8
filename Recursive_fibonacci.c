#include <stdio.h>
#include <stdlib.h>
static int count = 0;
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    count++;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("Enter the number n\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }

    printf("\nTime taken\n %d", count);
}