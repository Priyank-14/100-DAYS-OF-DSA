/*
Problem Statement:
Given target distance and arrays of positions and speeds of cars,
find number of car fleets reaching the destination.

Approach:
1. Pair position & speed
2. Sort cars by position in descending order
3. Compute time to reach target
4. Traverse from closest to farthest:
   - If current time > previous → new fleet
   - Else → joins existing fleet

Time Complexity: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Sort in descending order of position
int compare(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;

    printf("Enter number of cars: ");
    scanf("%d", &n);

    printf("Enter target distance: ");
    scanf("%d", &target);

    Car cars[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Car %d position: ", i + 1);
        scanf("%d", &cars[i].pos);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        printf("Car %d speed: ", i + 1);
        scanf("%d", &cars[i].speed);
    }

    // Step 1: Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    // Step 2: Traverse cars
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