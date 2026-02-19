#include<stdio.h>
#include<stdlib.h>
int main(){               
    int n,i,j;                            //Declaration
    scanf("%d",&n);                      //Accepting value from user
    int a[n];                            //Array declaration
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);               //Acccepting array elements
    int x=a[0], y=a[1];
    int min = abs(a[0] + a[1]);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            int sum = abs(a[i] + a[j]);
            if(sum < min){
                min = sum;
                x = a[i];
                y = a[j];
            }
        }
    }
    printf("%d %d",x,y);             //Required output statement
    return 0;
}
