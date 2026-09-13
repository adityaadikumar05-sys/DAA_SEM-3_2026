#include <stdio.h>

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) return;

    k = k % numsSize; // Handle cases where k >= numsSize
    if (k == 0) return;

    // Step 1: Reverse entire array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining n - k elements
    reverse(nums, k, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, n, k);

    // Print result
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], (i < n - 1) ? ", " : "");
    }
    printf("]\n");

    return 0;
}