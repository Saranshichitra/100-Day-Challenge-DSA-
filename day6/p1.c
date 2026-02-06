#include<stdio.h>
int main(){
    int n;                                         //Declaration
    scanf("%d", &n);                               //Accepting array size from the user
    int arr[n];                                    //Declaration of array
    for(int i=0; i<n ;i++) {                       
        scanf("%d", &arr[i]);                     //Accepting array elements one by one
    }
    for(int i=0; i<n-1; i++) {
        if(arr[i] != arr[i+1]){                  //Comparing the next element 
            printf("%d ", arr[i]);
        }
    }
    printf("%d ", arr[n-1]);
}