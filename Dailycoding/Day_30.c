#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int arr[], int n)
{
    int i = 0;

    while (i < n)
    {
        int correct = arr[i] - 1;

        if (arr[i] > 0 &&
            arr[i] <= n &&
            arr[i] != arr[correct])
        {
            swap(&arr[i], &arr[correct]);
        }
        else
        {
            i++;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main()
{
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("First missing positive = %d\n",
           firstMissingPositive(arr, n));

    return 0;
}
