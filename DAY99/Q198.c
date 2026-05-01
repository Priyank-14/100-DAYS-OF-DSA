/*
Problem Statement:
Given target and cars' positions & speeds,
find number of car fleets.

Approach:
- Sort cars by position descending
- Compute time to reach target
- Greedy merging
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;

    printf("Enter number of cars: ");
    scanf("%d", &n);

    printf("Enter target distance: ");
    scanf("%d", &target);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Car %d position: ", i + 1);
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        printf("Car %d speed: ", i + 1);
        scanf("%d", &speed[i]);
    }

    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    printf("Number of car fleets: %d\n", fleets);

    return 0;
}