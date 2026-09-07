#include <stdio.h>

void findTwoSum(const int arr[], int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]\n", i, j);
                return;
            }
        }
    }
}

int main(void) {
    int arr[] = {2, 7, 11, 15};
    int target = 9;

    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoSum(arr, n, target);

    return 0;
}