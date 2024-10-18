
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define MAX_WORD_LENGTH 50

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Binary Search function to search for a word in a sorted dictionary
int binarySearch(char *dictionary[], int size, char *target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Create lowercase versions of mid and target for case-insensitive comparison
        char lowerMid[MAX_WORD_LENGTH];
        strcpy(lowerMid, dictionary[mid]);
        toLowerCase(lowerMid);

        char lowerTarget[MAX_WORD_LENGTH];
        strcpy(lowerTarget, target);
        toLowerCase(lowerTarget);

        int comparison = strcmp(lowerMid, lowerTarget);
        if (comparison == 0) {
            return mid;  // Word found
        } else if (comparison < 0) {
            left = mid + 1;  // Target is in the right half
        } else {
            right = mid - 1;  // Target is in the left half
        }
    }

    return -1;  // Word not found
}

int main() {
    // Dictionary of fruit names
    char *dictionary[SIZE] = {
        "Apple", "Banana", "Cherry", "Date", "Fig",
        "Grape", "Kiwi", "Mango", "Orange", "Voracious"
    };

    char target[MAX_WORD_LENGTH];

    printf("This dictionary contains fruit names.\n");
    printf("Enter the word to search for: ");
    scanf("%49s", target);  // Limiting input to avoid buffer overflow

    int result = binarySearch(dictionary, SIZE, target);

    if (result != -1) {
        printf("The word '%s' was found at index %d.\n", target, result);
    } else {
        printf("The word '%s' was not found in the dictionary.\n", target);
    }

    return 0;
}
