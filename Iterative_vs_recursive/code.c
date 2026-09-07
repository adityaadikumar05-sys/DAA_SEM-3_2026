#include <stdio.h>
#include <time.h>

// Iterative method: O(n) time, O(1) space
unsigned long long fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    unsigned long long prev2 = 0;
    unsigned long long prev1 = 1;
    unsigned long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// Naive Recursive method: O(2^n) time, O(n) stack space
unsigned long long fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    // 40 is a good test value: fast enough to complete, slow enough to measure recursion
    int n = 40; 
    clock_t start, end;
    double time_taken;

    printf("Calculating Fibonacci(%d)...\n\n", n);

    // Measure Iterative Approach
    start = clock();
    unsigned long long iterResult = fibonacciIterative(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Iterative Result: %llu\n", iterResult);
    printf("Iterative Time  : %f seconds\n\n", time_taken);

    // Measure Recursive Approach
    start = clock();
    unsigned long long recurResult = fibonacciRecursive(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Recursive Result: %llu\n", recurResult);
    printf("Recursive Time  : %f seconds\n", time_taken);

    return 0;
}