#include <stdio.h>
int main() {
    int n;                                   //declaration
    scanf("%d", &n);                         //Accepting value from the user
    int arr[n];                              //Array declaration
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);               //Accepting array elements 
    }
    int count = 0;
    for(int i = 0; i < n; i++) {           //checking all subarrays
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;                   //counting the number of times sum of subarrays is zero
            }
        }
    }
    printf("%d", count);                  //Required output statement
    return 0;
}
