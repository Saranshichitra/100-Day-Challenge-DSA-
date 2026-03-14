#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        queue[++rear] = x;
    }
    while(front <= rear) {
        stack[++top] = queue[front++];
    }
    front = 0;
    rear = -1;
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }
    for(int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
