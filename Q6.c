/**6. Write a C program to find all pairs of elements in an array whose sum is equal to a given target
value. Each pair should be displayed only once.
Array: 2 7 4 5 1 3 Target: 6
Output: (2, 4), (5, 1)**/

#include <stdio.h>

void findPairs(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]);
    findPairs(arr, n, target);
    return 0;
}
