#include<stdio.h>
int main(){
    int r, c;                           //Declaration
    scanf("%d %d", &r, &c);             //Accepting value from user
    int m[r][c];                        //Declaration of matrix 
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &m[i][j]);      //Accepting matrix elements from the user
        } 
    }
    int sum=0;
      for(int i=0; i<r; i++){
            sum=sum+m[i][i];           //Calculating the sum
    }
    printf("%d", sum);                  //Required output statement
    return 0;
}