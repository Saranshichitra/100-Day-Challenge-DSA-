#include <stdio.h>
int fib(int n) {                                         //function
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);                     //Recursion
}
int main() {
    int n;                                            //declaration
    scanf("%d", &n);                                  //Accepting value from the user
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib(i));                        //calling function again and again to print the sum of last two numbers
    }
    return 0;
}
