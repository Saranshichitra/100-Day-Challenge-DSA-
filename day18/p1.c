#include <stdio.h>
int main(){
     int n, k;                              //declaration
    scanf("%d", &n);                        //Accepting value from the user
    int arr[n];                             //Array declaration
    for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);                  //Accepting array elements
    }
    scanf("%d", &k);                       //shift
    for(int i = n - k; i < n; i++)
        printf("%d ", arr[i]);
    for(int i = 0; i < n - k; i++)
        printf("%d ", arr[i]);
    return 0;
}