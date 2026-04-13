/*
Problem Statement:
Given a cost matrix, find the minimum cost to visit all cities exactly once
starting from city 0 and return back to city 0 (Travelling Salesman Problem).

Optimized using DP + Bitmasking.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int dp[MAX][1 << MAX];

// DP function
int solve(int mask, int pos) {
    
    // If all cities visited
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }
    
    // Memoization
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int ans = INT_MAX;
    
    // Try all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            
            int newCost = cost[pos][city] +
                          solve(mask | (1 << city), city);
            
            if (newCost < ans) {
                ans = newCost;
            }
        }
    }
    
    return dp[pos][mask] = ans;
}

int main() {
    
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    // Edge case
    if (n == 1) {
        printf("Minimum travelling cost: 0\n");
        return 0;
    }
    
    // Initialize DP table
    memset(dp, -1, sizeof(dp));
    
    int result = solve(1, 0); // start from city 0
    
    printf("Minimum travelling cost: %d\n", result);
    
    return 0;
}