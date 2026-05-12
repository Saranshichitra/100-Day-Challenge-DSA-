#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start;
    int end;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {

    while(1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}
int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;
    return m1->start - m2->start;
}

int minMeetingRooms(struct Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(struct Meeting), compare);
    int heap[100];
    int heapSize = 0;
    push(heap, &heapSize, meetings[0].end);
    for(int i = 1; i < n; i++) {
        int start = meetings[i].start;
        int end = meetings[i].end;
        if(start >= top(heap)) {
            pop(heap, &heapSize);
        }
        push(heap, &heapSize, end);
    }
    return heapSize;
}
int main() {
    struct Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };
    int n = sizeof(meetings) / sizeof(meetings[0]);
    printf("Minimum rooms required = %d\n",
           minMeetingRooms(meetings, n));
    return 0;
}