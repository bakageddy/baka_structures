#include <stdio.h>

int G[10][10], visited[10], n;
void dfs(int v);
int  main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dfs(0);
    }
}

void dfs(int v) {
    int i;
    printf("\n%d", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (!visited[i] && G[v][i] == 1)
            dfs(i);
}
