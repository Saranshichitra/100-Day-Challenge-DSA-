#include<stdio.h>
#include <string.h>
int main(){
    char str[100];                                       //Declaration
    scanf("%s", str);                                    //Accepting string from the user
    for(int i=strlen(str)-1 ; i>=0; i--){
            printf("%c", str[i]);                        //printing the reversed characters one by one
    }
}