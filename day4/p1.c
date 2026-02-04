//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);                                     //Accepting array length from user
    int arr[n];                                          //Declarating an array
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);                            //Accepting array elements
    }
    int *l=arr;                                         //Shifting to the left pointer
    int *r=arr+n-1;                                     //Shifting to the left pointer
    int temp;                                           //Declarating a temporaray variable for swaping
    while(l<r) {
        temp=*l;
        *l=*r;
        *r=temp;
         l++;
         r--;
    }
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);                      //Output statement to print the swapped elements
    }

    return 0;
}