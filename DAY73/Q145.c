/*
Problem Statement:
Given a string s consisting of lowercase English letters, find and return
the first character that does not repeat in the string.
If all characters repeat, return '$'.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    printf("Enter the string: ");
    scanf("%s", s);

    int freq[26] = {0};

    // Count frequency of each character
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; i < strlen(s); i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");

    return 0;
}