#include<stdio.h>
int main(){
    int n;                           //Declaration
    scanf("%d", &n);                 //Accepting array size from user
    int arr[n];                      //Array declaration
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);       //Accepting array elements one by one
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("Max: %d\n", max);      //Output statement to print the maximum value
    printf("Min: %d", min);        //Output statement to print the minimum value
 return 0;
}