#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure binary search is performed on the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        // Boundary conditions using INT_MIN and INT_MAX
        int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];

        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        // Check if partition is correct
        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 1) {
                return (double)MAX(left1, left2);
            } else {
                return (MAX(left1, left2) + MIN(right1, right2)) / 2.0;
            }
        } else if (left1 > right2) {
            high = i - 1; // Move left in nums1
        } else {
            low = i + 1;  // Move right in nums1
        }
    }

    return 0.0;
}

int main() {
    // Example 1: Total odd elements
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int m1 = sizeof(nums1) / sizeof(nums1[0]);
    int n1 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Median 1: %.5f\n", findMedianSortedArrays(nums1, m1, nums2, n1)); // Expected: 2.00000

    // Example 2: Total even elements
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    int m2 = sizeof(nums3) / sizeof(nums3[0]);
    int n2 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Median 2: %.5f\n", findMedianSortedArrays(nums3, m2, nums4, n2)); // Expected: 2.50000

    return 0;
}