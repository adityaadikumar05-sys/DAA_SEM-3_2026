#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

int quickSelect(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int p = partition(arr, low, high);

        if (p == target)
            return arr[p];

        if (p < target)
            low = p + 1;
        else
            high = p - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    // kth largest = index n-k in ascending order
    int answer = quickSelect(arr, 0, n - 1, n - k);

    printf("%dth largest element = %d\n", k, answer);

    return 0;
}
