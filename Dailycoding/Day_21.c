#include <stdio.h>

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];
    int index = 0;

    // Store non-zero elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            temp[index++] = arr[i];
    }

    // Add zeros
    while (index < n)
    {
        temp[index++] = 0;
    }

    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);

    return 0;
}
