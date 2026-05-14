#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    struct Car cars[n];
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, n, sizeof(struct Car), compare);
    int fleets = 0;
    double maxTime = 0.0;
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;
        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);
    printf("Number of Car Fleets: %d\n",
           carFleet(target, position, speed, n));
    return 0;
}