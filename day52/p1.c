#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* queue[n];   
    int front = 0, rear = 0;
    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->val == n1 || root->val == n2)
        return root;
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    else
        return right;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    struct Node* root = buildTree(arr, n);
    struct Node* ans = LCA(root, n1, n2);
    if (ans != NULL)
        printf("%d", ans->val);
    else
        printf("-1");
    return 0;
}