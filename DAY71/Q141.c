/*
Problem Statement:
Implement a hash table using Quadratic Probing with the formula:
h(k, i) = (h(k) + i*i) % m

Perform INSERT and SEARCH operations.
Print "FOUND" or "NOT FOUND" for SEARCH operations.
*/

#include <stdio.h>

#define EMPTY -1
#define MAX 100

int hashTable[MAX];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            return;
        }
    }

    printf("Hash table is full, cannot insert %d\n", key);
}

// Search using quadratic probing
void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (hashTable[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (hashTable[index] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    // Initialize table
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;

        printf("Enter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(key, m);
        } else if (op[0] == 'S') { // SEARCH
            search(key, m);
        }
    }

    return 0;
}