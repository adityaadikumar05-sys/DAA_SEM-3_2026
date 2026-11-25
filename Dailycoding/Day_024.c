#include <stdio.h>

int findPeakElement(int nums[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int index = findPeakElement(nums, n);

    printf("Peak element = %d\n", nums[index]);
    printf("Peak index = %d\n", index);

    return 0;
}
