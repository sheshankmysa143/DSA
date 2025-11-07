#include <stdio.h>

int a[10][10], n, vis[10], stack[10];

int dfs(int v) {
    vis[v] = 1;
    stack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (a[v][i]) {
            if (!vis[i] && dfs(i))
                return 1;
            if (stack[i])
                return 1;
        }
    }
    stack[v] = 0;
    return 0;
}

int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        if (!vis[i] && dfs(i)) {
            printf("Cycle detected\n");
            return 0;
        }

    printf("No cycle detected\n");
    return 0;
}

