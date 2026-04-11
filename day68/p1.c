#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void kahnTopologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int result[MAX], index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }
    while (!isEmpty()) {
        int node = dequeue();
        result[index++] = node;
        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }
    if (index != n) {
        printf("Graph has a cycle! No Topological Ordering.\n");
        return;
    }
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    kahnTopologicalSort(graph, n);
    return 0;
}