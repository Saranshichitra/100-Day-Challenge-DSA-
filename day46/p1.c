#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    struct Node* temp = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}

int isEmpty() {
    return front == -1;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* current = dequeue();
        printf("%d ", current->data);
        if (current->left)
            enqueue(current->left);
        if (current->right)
            enqueue(current->right);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);

    return 0;
}