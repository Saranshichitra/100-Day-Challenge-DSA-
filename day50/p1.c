#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}
int main() {
    struct TreeNode n1 = {10, NULL, NULL};
    struct TreeNode n2 = {5, NULL, NULL};
    struct TreeNode n3 = {15, NULL, NULL};
    n1.left = &n2;
    n1.right = &n3;
    int val = 5;
    struct TreeNode* result = searchBST(&n1, val);
    if (result != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
    return 0;
}