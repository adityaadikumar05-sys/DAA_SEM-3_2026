#include <stdio.h>

int squareRoot(int n)
{
    if (n == 0 || n == 1)
        return n;

    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Avoid mid * mid overflow
        if (mid <= n / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Square root is not real.\n");
    else
        printf("Square root = %d\n", squareRoot(n));

    return 0;
}
