#include<stdio.h>
int main(){
    int r, c, flag=0;                           //Declaration
    scanf("%d %d", &r, &c);                     //Accepting value from user
    int m[r][c];                                //Declaration of matrix  
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            scanf("%d", &m[i][j]);              //Accepting the matrix elements from the user
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c; j++){
            if(i != j){
                if(m[i][j]!=0){
                    flag=1;
                    break;
                }
            }
        else{
            if(m[i][j] != 1){
                flag=1;
                break;
            }
        }
    }
}
if(flag==0){
    printf("Identity matrix");                 //Output statement if condition persists
}
else{
    printf("Not an identity matrix");          //Output statement if condition does not persists
}
return 0;
}