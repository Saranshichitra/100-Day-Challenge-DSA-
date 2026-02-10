#include<stdio.h>
#include<string.h>
int main(){
    char str[100];                                    //Declaration
    scanf("%s", str);                                 //Accepting string from the user
    int n=strlen(str);                                //To calculate the length of the string
    int k=0;
    for(int i=0; i<n; i++){
        if(str[i] != str[n-i-1])                     //Comparing string
        k=1;
        break;
    }
    if(k==0) {
        printf("YES");                             //Output statement if condition persists
    }
    else {
        printf("NO");                             //Output statement if condition does not persist
    }
    return 0;
}