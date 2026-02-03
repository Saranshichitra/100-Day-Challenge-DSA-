#include<stdio.h>
int main() {
    int n, nf, found, i1;                     //Declarations
    scanf("%d", &n);                          //Asking value from the user
    int arr[n];                               //Array declaration
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);                 //Accepting array elements from user
    }
    scanf("%d", &nf);                         //Asking user number to be found
    for(int i=0; i<n; i++){                   
        if(nf == arr[i]){                    //Comparing each element with the number to be found
            found=1;
            i1=i;
            break;
        }
    }
    if(found == 1){                           
        printf("Number found at index %d with %d comparisons", i1, i1+1);    //Output statement if the condition persists
    }
}