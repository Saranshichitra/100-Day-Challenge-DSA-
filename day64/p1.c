#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(struct Node* adj[], int n, int s) {
    int visited[MAX] = {0};
    enqueue(s);
    visited[s] = 1;
    printf("BFS Traversal: ");
    while (front <= rear) {
        int curr = dequeue();
        printf("%d ", curr);
        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    struct Node* adj[MAX];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); 
    }
    printf("Enter source: ");
    scanf("%d", &s);
    BFS(adj, n, s);
    return 0;
}