/*
Problem Statement:
Given an array of candidate names where each name represents a vote,
determine the candidate with maximum votes.
In case of a tie, return the lexicographically smallest name.
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[MAX][LEN];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[MAX][LEN];
    int count[MAX] = {0};
    int u = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < u; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[u], votes[i]);
            count[u] = 1;
            u++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < u; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}