#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;
    int low = 0, high = n, mid, ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid <= n / mid) {
            ans = mid;        
            low = mid + 1;   
        } else {
            high = mid - 1;  
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", integerSqrt(n));
    return 0;
}