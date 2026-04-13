/*
Problem Statement:
Given a string s consisting of lowercase letters, find the first repeated character.
A character is considered repeated if it appears more than once, and among all such
characters, the one whose second occurrence has the smallest index should be returned.
If no character is repeated, print -1.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    printf("Enter the string: ");
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        freq[index]++;

        if (freq[index] == 2) {
            printf("First repeated character: %c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}