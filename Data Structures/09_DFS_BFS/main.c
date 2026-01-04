#include <stdio.h>
#include <stdlib.h>

#define V 5 // Düğüm sayısı

int queue[V], front = -1, rear = -1;

void enqueue(int item) {
    if (rear == V - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1) return -1;
    int item = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return item;
}

void BFS(int adj[V][V], int start) {
    int visited[V] = {0};
    enqueue(start);
    visited[start] = 1;
    printf("BFS Siralamasi: ");
    while (front != -1) {
        int curr = dequeue();
        printf("%d ", curr);
        for (int i = 0; i < V; i++) {
            if (adj[curr][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int adj[V][V], int visited[V], int start) {
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < V; i++) {
        if (adj[start][i] && !visited[i]) {
            DFS(adj, visited, i);
        }
    }
}

int main() {
    int adj[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    BFS(adj, 0);
    
    int visited[V] = {0};
    printf("DFS Siralamasi: ");
    DFS(adj, visited, 0);
    printf("\n");
    
    return 0;
}