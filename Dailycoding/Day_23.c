#include <stdio.h>

void sortEvenOdd(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // Already even
        if (arr[left] % 2 == 0)
        {
            left++;
        }

        // Already odd
        else if (arr[right] % 2 != 0)
        {
            right--;
        }

        else
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortEvenOdd(arr, n);

    printf("Result: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
