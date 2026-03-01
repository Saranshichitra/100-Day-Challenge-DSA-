#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* rotate(struct Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    struct Node *temp = head;
    int count = 1;
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    temp->next = head;
    k = k % count;
    int s = count - k;
    struct Node* newT = head;
    for(int i = 1; i < s; i++) {
        newT = newT->next;
    }
    struct Node* newH = newT->next;
    newT->next = NULL;
    return newH;
}

int main() {
    int n, value, k;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    scanf("%d", &n);
    if(n <= 0)
        return 0;
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;
    temp = head;
    for(int i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    scanf("%d", &k);
    head = rotate(head, k);
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}