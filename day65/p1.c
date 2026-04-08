#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];  

int dfs(int node, int parent, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) { 
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}

int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  
    }
    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}