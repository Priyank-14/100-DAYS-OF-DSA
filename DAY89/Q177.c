/*
Problem Statement:
Allocate books to m students such that:
- Each student gets at least one book
- Books are allocated contiguously
- The maximum pages assigned to a student is minimized

Approach:
- Binary Search on answer (max pages)
- Greedy check for feasibility

Time Complexity: O(n log(sum))
*/

#include <stdio.h>

// Check if allocation is possible with maxPages limit
int canAllocate(int books[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages)
            return 0;  // single book exceeds limit

        if (currentSum + books[i] <= maxPages) {
            currentSum += books[i];
        } else {
            students++;
            currentSum = books[i];

            if (students > m)
                return 0;
        }
    }

    return 1;
}

int main() {
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int books[n];
    int sum = 0, maxBook = 0;

    printf("Enter pages in each book:\n");
    for (int i = 0; i < n; i++) {
        printf("Book %d: ", i + 1);
        scanf("%d", &books[i]);

        sum += books[i];
        if (books[i] > maxBook)
            maxBook = books[i];
    }

    int left = maxBook;  // minimum possible
    int right = sum;     // maximum possible
    int ans = sum;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(books, n, m, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller max
        } else {
            left = mid + 1;
        }
    }

    printf("Minimum maximum pages: %d\n", ans);

    return 0;
}