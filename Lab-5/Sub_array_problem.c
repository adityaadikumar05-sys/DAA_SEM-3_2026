#include <stdio.h>

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    int currentSum = a[0];
    int maxSum = a[0];

    for (int i = 1; i < n; i++) {

        if (currentSum + a[i] > a[i])
            currentSum = currentSum + a[i];
        else
            currentSum = a[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    printf("Maximum Subarray Sum = %d\n", maxSum);

    return 0;
}