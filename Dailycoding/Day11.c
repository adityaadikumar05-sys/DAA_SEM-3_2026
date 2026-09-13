#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));

    int left = 0;
    int right = numsSize - 1;
    int idx = numsSize - 1; // Fill the result array from largest to smallest

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[idx--] = leftSquare;
            left++;
        } else {
            result[idx--] = rightSquare;
            right--;
        }
    }

    return result;
}

int main() {
    // Array sorted in non-decreasing order
    int nums[] = {-5, -4, -3, 1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = sortedSquares(nums, n, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], (i < returnSize - 1) ? " " : "");
    }
    printf("\n");

    free(result);
    return 0;
}