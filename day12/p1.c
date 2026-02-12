#include<stdio.h>
int main(){
    int i, j, r, c, k=0;                          //Declaration and initialization
    scanf("%d %d", &r ,&c );                      //Accepting value from the user
    int m[r][c];                                 //Declaration of matrix
    int n[c][r];                                 //Declaration of transpose matrix
    for(i=0; i<r ;i++){
        for(j=0; j<c ; j++){
            scanf("%d", &m[i][j]);              //Initialization of transpose matrix
        }
    }
    for(i=0; i<r ;i++){
        for(j=0; j<c ; j++){
            n[j][i]=m[i][j];                       
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(m[i][j] != n[i][j]){
                k=1;
                break;
            }
        }
        if(k==1) break;
    }

    if(k==0){
        printf("Symmetric Matrix");
    }
    else{
        printf("Unsymmetric Matrix");
    }

    return 0;
}
