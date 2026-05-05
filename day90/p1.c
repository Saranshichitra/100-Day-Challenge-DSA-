#include <stdio.h>

int canPaint(int boards[], int n, int k, int max_time) {
    int painters = 1;
    int curr_time = 0;

    for (int i = 0; i < n; i++) {
        if (curr_time + boards[i] <= max_time) {
            curr_time += boards[i];
        } else {
            painters++;
            curr_time = boards[i];

            if (painters > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0];
    int high = 0;

    // Find max element and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1; // increase time
        }
    }

    return result;
}

int main() {
    int n = 4, k = 2;
    int boards[] = {10, 20, 30, 40};

    printf("%d\n", minTime(boards, n, k));
    return 0;
}