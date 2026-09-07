#include <stdio.h>

int main() {
    long long num;
    int digit_sum = 0;

    printf("Enter the number: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }

    long long temp = num;

    // Calculate sum of digits
    while (temp > 0) {
        digit_sum += temp % 10;
        temp /= 10;
    }

    // Missing digit = (Sum of 0 to 9) - (Sum of present digits)
    int missing_digit = 45 - digit_sum;

    printf("%d\n", missing_digit);

    return 0;
}