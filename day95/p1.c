#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    float arr[N] = {0.78, 0.17, 0.39, 0.26, 0.72,
                    0.94, 0.21, 0.12, 0.23, 0.68};
    int n = N;
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    bucketSort(arr, n);
    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}