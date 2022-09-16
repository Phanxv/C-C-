#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 11

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index, v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
int printSolution(int dist[], int n, int parent[])
{
    int src = 0, i;
    printf("Vertex\t  Distance\tPath");
    for (i = 1; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V], count, v;
    bool sptSet[V];
    int parent[V], i;
    for (i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent);
}
int main()
{
    int graph[V][V] = {{0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                       {4, 0, 10, 1, 8, 0, 0, 0, 0, 0, 0},
                       {1, 10, 0, 5, 0, 0, 9, 0, 0, 0, 0},
                       {0, 1, 5, 0, 0, 3, 0, 0, 0, 0, 0},
                       {0, 8, 0, 0, 0, 1, 0, 2, 0, 0, 0},
                       {0, 0, 0, 3, 1, 0, 1, 3, 7, 0, 0},
                       {0, 0, 9, 0, 0, 1, 0, 0, 0, 2, 0},
                       {0, 0, 0, 0, 2, 3, 0, 0, 1, 0, 4},
                       {0, 0, 0, 0, 0, 7, 0, 1, 0, 1, 3},
                       {0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 5},
                       {0, 0, 0, 0, 0, 0, 0, 4, 3, 5, 0}};
    dijkstra(graph, 0);
    return 0;
}
