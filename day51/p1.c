#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int find(struct Node* root, int a, int b) {
    if (a < root->data && b < root->data)
        return find(root->left, a, b);
    if (a > root->data && b > root->data)
        return find(root->right, a, b);
    return root->data; 
}

int main() {
    int n, x;
    struct Node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", find(root, a, b));
    return 0;
}