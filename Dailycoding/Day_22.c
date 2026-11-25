#include <stdio.h>

#define BUCKETS 10

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n)
{
    int bucket[BUCKETS][n];
    int count[BUCKETS] = {0};

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] / 10;

        if (index >= BUCKETS)
            index = BUCKETS - 1;

        bucket[index][count[index]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < BUCKETS; i++)
        insertionSort(bucket[i], count[i]);

    // Combine buckets
    int k = 0;

    for (int i = 0; i < BUCKETS; i++)
    {
        for (int j = 0; j < count[i]; j++)
            arr[k++] = bucket[i][j];
    }
}

int main()
{
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
