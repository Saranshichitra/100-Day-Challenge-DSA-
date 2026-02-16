#include <stdio.h>
int main() {
    int n, count;                     //Declaration
    scanf("%d",&n);                   //Accepting value from user
    int arr[n];                       //Array declaration
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);         //Accepting array elements 
    }
    for(int i=0;i<n;i++){
        int found = 0;
        for(int k=0;k<i;k++){
            if(arr[i] == arr[k]){
                found = 1;
                break;
            }
        }
        if(found){
        continue;
        }
        count = 0;
        for(int j=i; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        printf("%d:%d ", arr[i], count);    //Required output statement
    }
    return 0;
}
