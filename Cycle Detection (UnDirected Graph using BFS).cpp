#include <stdio.h>

int a[10][10], n;

int cycleBFS(int s, int v[]) {
    int q[20], front = 0, rear = 0, i, u;
    v[s] = 1;
    q[rear++] = s;

    while (front < rear) {
        u = q[front++];
        for (i = 0; i < n; i++) {
            if (a[u][i]) {
                if (!v[i]) {
                    v[i] = 1;
                    q[rear++] = i;
                } 
                else if (i != s) // visited again ? cycle
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j, v[10] = {0}, cycle = 0;
    printf("Enter vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        if (!v[i] && cycleBFS(i, v)) {
            cycle = 1;
            break;
        }

    printf(cycle ? "Cycle found\n" : "No cycle\n");
    return 0;
}

