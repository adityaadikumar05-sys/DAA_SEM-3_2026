#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    long long diff = (long long)(*(int*)a) - (long long)(*(int*)b);
    return (diff > 0) - (diff < 0);
}

// Function to find the smallest difference
int findSmallestDifference(int* arr1, int n, int* arr2, int m, int* bestPair1, int* bestPair2) {
    // Step 1: Sort both arrays
    qsort(arr1, n, sizeof(int), compare);
    qsort(arr2, m, sizeof(int), compare);

    int i = 0, j = 0;
    long long minDiff = LLONG_MAX;

    // Step 2: Two-pointer scan
    while (i < n && j < m) {
        long long currentDiff = llabs((long long)arr1[i] - (long long)arr2[j]);

        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            *bestPair1 = arr1[i];
            *bestPair2 = arr2[j];
        }

        // If difference is 0, no smaller difference is possible
        if (minDiff == 0) {
            break;
        }

        // Move pointer pointing to the smaller element
        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return (int)minDiff;
}

int main() {
    int arr1[] = {1, 3, 15, 11, 2};
    int arr2[] = {23, 127, 235, 19, 8};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int pair1, pair2;
    int minDiff = findSmallestDifference(arr1, n, arr2, m, &pair1, &pair2);

    printf("Smallest Difference: %d\n", minDiff);
    printf("Elements causing smallest difference: %d from arr1 and %d from arr2\n", pair1, pair2);

    return 0;
}