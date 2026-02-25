#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
        return newnode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

int count(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, x, key;
    struct Node* head = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }
    scanf("%d", &key);
    printf("%d", count(head, key));

    return 0;
}