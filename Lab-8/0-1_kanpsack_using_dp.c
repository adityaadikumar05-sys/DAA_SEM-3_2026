#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weight[], int profit[], int n)
{
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum Profit = %d\n",
           knapsack(capacity, weight, profit, n));

    return 0;
}
