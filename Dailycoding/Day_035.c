#include <stdio.h>
#include <limits.h>

int thirdMax(int arr[], int n)
{
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long x = arr[i];

        // Ignore duplicates
        if (x == first || x == second || x == third)
            continue;

        if (x > first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second)
        {
            third = second;
            second = x;
        }
        else if (x > third)
        {
            third = x;
        }
    }

    // If third distinct maximum doesn't exist,
    // return maximum
    if (third == LLONG_MIN)
        return (int)first;

    return (int)third;
}

int main()
{
    int arr[] = {2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Third maximum = %d\n", thirdMax(arr, n));

    return 0;
}
