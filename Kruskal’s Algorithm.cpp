#include <stdio.h>

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v) {
    parent[find(parent, u)] = find(parent, v);
}

int main() {
    int n, m, i, j, u[30], v[30], w[30], parent[30], temp, total = 0;
    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);

    for (i = 0; i < n; i++) 
	parent[i] = i;
    // Sort edges by weight
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - i - 1; j++)
            if (w[j] > w[j + 1]) {
                temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }

    printf("\nEdges in MST:\n");
    for (i = 0; i < m; i++) {
        int a = find(parent, u[i]);
        int b = find(parent, v[i]);
        if (a != b) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            total += w[i];
            unionSet(parent, a, b);
        }
    }

    printf("Total cost = %d\n", total);
}

