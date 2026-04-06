#include <stdio.h>

#define MAX 100
int vis[MAX];
void dfs(int v, int n, int adj[MAX][MAX]) {
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !vis[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    printf("DFS Traversal: ");
    dfs(s, n, adj);
    return 0;
}