#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}
struct Q {
    struct Node* node;
    int hd;
} q[100];

int front = 0, rear = -1;

void push(struct Node* n, int hd) {
    q[++rear] = (struct Q){n, hd};
}

struct Q pop() {
    return q[front++];
}

struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* tempQ[100];
    int f = 0, r = -1;
    tempQ[++r] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = tempQ[f++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            tempQ[++r] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            tempQ[++r] = curr->right;
        }
        i++;
    }
    return root;
}

void vertical(struct Node* root) {
    int map[200][50], count[200] = {0}, offset = 100;
    int min = 0, max = 0;
    push(root, 0);
    while (front <= rear) {
        struct Q t = pop();
        int hd = t.hd;
        if (hd < min) min = hd;
        if (hd > max) max = hd;
        map[hd + offset][count[hd + offset]++] = t.node->data;
        if (t.node->left) push(t.node->left, hd - 1);
        if (t.node->right) push(t.node->right, hd + 1);
    }
    printf("\nVertical Order Traversal:\n");
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    vertical(root);
    return 0;
}