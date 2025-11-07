#include <stdio.h>
#include <limits.h>

#define V 5

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[V], parent[V], mst[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mst[i] = 0;

    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < V; v++)
            if (!mst[v] && key[v] < min)
                min = key[v], u = v;

        mst[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v])
                key[v] = graph[u][v], parent[v] = u;
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);

    return 0;
}

