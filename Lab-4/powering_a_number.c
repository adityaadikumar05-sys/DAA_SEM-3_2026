#include <stdio.h>
#include <time.h>

// Divide-and-Conquer approach: O(log n)
long long powerOptimized(int x, int n) {
    if (n == 0) {
        return 1;
    }

    long long y = powerOptimized(x, n / 2);

    if (n % 2 == 0) {
        return y * y;
    } else {
        return x * y * y;
    }
}

// Basic iterative approach: O(n)
long long powerBasic(int x, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

int main() {
    int x, n;
    clock_t start, end;
    double time_basic, time_optimized;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter non-negative exponent (n): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Exponent must be a non-negative integer.\n");
        return 1;
    }

    // Measure basic power method
    start = clock();
    long long res_basic = powerBasic(x, n);
    end = clock();
    time_basic = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure optimized power method
    start = clock();
    long long res_opt = powerOptimized(x, n);
    end = clock();
    time_optimized = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n--- Results ---\n");
    printf("Basic Method:     %d^%d = %lld | Time: %f seconds\n", x, n, res_basic, time_basic);
    printf("Optimized Method: %d^%d = %lld | Time: %f seconds\n", x, n, res_opt, time_optimized);

    return 0;
}