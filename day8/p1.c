#include<stdio.h>
int power(int num, int pow){                            //Function
    if(pow==0)                                          //Anything raised to the power 0 is always 1
    return 1;
    else
    return num * power(num, pow-1);                     //Calling function in the function itself-Recursion
}
int main(){
    int num, pow;                                       //Declaration
    scanf("%d %d", &num, &pow);                         //Accepting value from the user
    printf("%d", power(num, pow));                      //Printing the final value on calling the power function
}