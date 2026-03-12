#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int lar = i;        
    int l = 2*i + 1;     
    int r = 2*i + 2;    
    if(l < n && arr[l] > arr[lar])
        lar = l;
    if(r < n && arr[r] > arr[lar])
        lar = r;
    if(lar != i)
    {
        int temp = arr[i];
        arr[i] = arr[lar];
        arr[lar] = temp;

        heapify(arr, n, lar);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = n-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}