#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top >= 0)
        top--;
}

void multipop(int k) {
    while (k-- && top >= 0) {
        pop();
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    multipop(2);

    printf("Stack after multipop:\n");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    return 0;
}