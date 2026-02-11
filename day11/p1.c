#include<stdio.h>
int main(){
    int r1, c1, r2, c2;                             //Declaration
    printf("Enter the number of rows and columns of both the matrices");
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);             //Accepting value from user
    int m1[r1][c1], m2[r2][c2], sum[r1][c1];
    printf("Enter the elemnts of first matrix");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d", &m1[i][j]);                    //Accepting the first matrix from user
         }
    }
    printf("Enter the elemnts of second matrix");
     for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d", &m2[i][j]);                    //Accepting the second matrix from user
        }
    }
    if((r1 != r2) || (c1 != c2)){                       //Checking whether addition is possible
        printf("Addition not possible");
    }

    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            sum[i][j]=m1[i][j]+m2[i][j];              //Calculating sum
        }
    }
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("%d  ", sum[i][j]);              //Printing the required matrix
        }
        printf("\n");
    }

}