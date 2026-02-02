/*Insert an Element in an Array
Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space.8*/
#include<stdio.h>
int main(){
    int n, pos, num;
    scanf("%d", &n);
    int arr[n+1];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);
    scanf("%d", &num);
    for(int i=n+1;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=num;
    for(int i=0;i<n+1;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
