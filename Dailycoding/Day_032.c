#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

void threeSum(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0)
            {
                printf("%d %d %d\n",
                       arr[i], arr[left], arr[right]);

                int leftValue = arr[left];
                int rightValue = arr[right];

                while (left < right &&
                       arr[left] == leftValue)
                    left++;

                while (left < right &&
                       arr[right] == rightValue)
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 0, 3, -2, -1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unique triplets:\n");

    threeSum(arr, n);

    return 0;
}
