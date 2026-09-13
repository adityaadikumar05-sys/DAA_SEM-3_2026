#include <stdio.h>

/**
 * Modifies the array in-place so that each unique element appears once.
 * Returns the number of unique elements (k).
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int writeIndex = 1; // Index where the next unique element will be placed

    for (int i = 1; i < numsSize; i++) {
        // Since the array is sorted, any new value differs from nums[i - 1]
        if (nums[i] != nums[i - 1]) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }

    return writeIndex;
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, n);

    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: [");
    for (int i = 0; i < k; i++) {
        printf("%d%s", nums[i], (i < k - 1) ? ", " : "");
    }
    printf("]\n");

    return 0;
}