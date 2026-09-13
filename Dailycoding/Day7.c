#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == nums[mid ^ 1]) {
            
            low = mid + 1;
        } else {
           
            high = mid;
        }
    }

    return nums[low];
}

int main() {
    
    int nums1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %d\n", singleNonDuplicate(nums1, size1)); 

    int nums2[] = {3, 3, 7, 7, 10, 11, 11};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %d\n", singleNonDuplicate(nums2, size2)); 

    int n;
    printf("\nEnter number of elements in array (must be odd): ");
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        printf("Enter %d sorted elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Single element is: %d\n", singleNonDuplicate(arr, n));
    }

    return 0;
}