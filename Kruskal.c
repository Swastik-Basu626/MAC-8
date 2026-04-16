#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set (Union-Find)
int parent[MAX];

// Find with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Comparator for sorting edges
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edges in MST:\n");

    int count = 0, i = 0;
    while (count < V - 1 && i < E) {
        struct Edge e = edges[i++];

        int u = find(e.u);
        int v = find(e.v);

        // If no cycle
        if (u != v) {
            printf("%d - %d : %d\n", e.u, e.v, e.weight);
            unionSet(u, v);
            count++;
        }
    }

    return 0;
}