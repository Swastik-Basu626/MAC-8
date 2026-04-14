#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}

void insert(int val) {
    int i = size++;
    heap[i] = val;
    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void deleteRoot() {
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

int main() {
    insert(10);
    insert(40);
    insert(20);
    insert(5);

    int n = size;

    for (int i = 0; i < n; i++) {
        printf("Deleted: %d\n", heap[0]);
        deleteRoot();
    }

    return 0;
}