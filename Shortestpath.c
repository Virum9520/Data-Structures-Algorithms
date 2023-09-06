#include <stdio.h>
#include <stdbool.h>
#define INF 999999

void dijkstra(int graph[100][100], int n, int start) 
{
    int dist[n];
    bool visited[n];
    int i, j, min_dist, u;
    
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
     dist[start] = 0;
    
    for (i = 0; i < n-1; i++) {
        min_dist = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = true;
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INF && dist[u]+graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printf("Shortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        printf("%d -> %d: %d\n", start, i, dist[i]);
    }
}

int main() {
    int graph[100][100], n, i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dijkstra(graph, n, start);
    return 0;
}