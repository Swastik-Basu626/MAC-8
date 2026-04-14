#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value) {
    int i = size++;
    heap[i] = value;

    // Heapify up
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);

    display();
    return 0;
}