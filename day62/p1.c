#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;
        temp = newNode(u);
        temp->next = adj[v];
        adj[v] = temp;
    }
    for(int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}