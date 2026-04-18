#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char arr[100][50];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    int max = 0;
    char winner[50];
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            strcpy(winner, arr[i]);
        } 
        else if (count == max) {
            if (strcmp(arr[i], winner) < 0) {
                strcpy(winner, arr[i]);
            }
        }
    }
    printf("%s %d\n", winner, max);
    return 0;
}