#include <stdio.h>

int heap[1000];
int size = 0;

void insert(int x)
{
    int i = size;
    heap[size++] = x;
    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMin()
{
    if(size == 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[size-1];
    size--;
    int i = 0;
    while(2*i+1 < size)
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int smallest = l;
        if(r < size && heap[r] < heap[l])
            smallest = r;

        if(heap[i] > heap[smallest])
        {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;

            i = smallest;
        }
        else
            break;
    }
    return min;
}

int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n)
    {
        char op[20];
        scanf("%s", op);
        if(op[0] == 'i')   
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'p')   
        {
            printf("%d\n", peek());
        }
        else if(op[0] == 'e') 
        {
            printf("%d\n", extractMin());
        }
        n--;
    }

    return 0;
}