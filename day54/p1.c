#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if(n == 0) return 0;
    printf("Enter root value: ");
    scanf("%d", &val);
    if(val == -1) return 0;
    struct Node* root = createNode(val);
    struct Node* q[n];
    int front = 0, rear = 0;
    q[rear++] = root;
    while(front < rear) {
        struct Node* curr = q[front++];
        printf("Enter left of %d (-1 for NULL): ", curr->data);
        scanf("%d", &val);
        if(val != -1) {
            curr->left = createNode(val);
            q[rear++] = curr->left;
        }
        printf("Enter right of %d (-1 for NULL): ", curr->data);
        scanf("%d", &val);
        if(val != -1) {
            curr->right = createNode(val);
            q[rear++] = curr->right;
        }
    }
    front = rear = 0;
    q[rear++] = root;
    int leftToRight = 1;
    printf("Zigzag Traversal: ");
    while(front < rear) {
        int size = rear - front;
        int level[size]; 
        for(int i = 0; i < size; i++) {
            struct Node* curr = q[front++];
            int index = leftToRight ? i : size - 1 - i;
            level[index] = curr->data;
            if(curr->left) q[rear++] = curr->left;
            if(curr->right) q[rear++] = curr->right;
        }
        for(int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
    return 0;
}