#include <stdio.h>

#define V 5 // Düğüm sayısı

void findCluster(int graph[V][V], int visited[], int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            findCluster(graph, visited, i);
        }
    }
}

int main() {
    // Komşuluk matrisi (0 ve 1'lerden oluşur)
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[V] = {0};
    int clusterCount = 0;

    printf("Graph Cluster Analizi:\n");
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            findCluster(graph, visited, i);
            printf("\n");
        }
    }

    return 0;
}