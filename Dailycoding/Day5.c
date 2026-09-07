#include <stdio.h>

int main(void) {
    unsigned int number;
    unsigned int temp;
    int binary[32];

    int index = 0;
    int ones = 0;
    int zeros = 0;
    int currentOnes = 0;
    int longestOnes = 0;

    printf("Enter a decimal number: ");
    scanf("%u", &number);

    if (number == 0) {
        printf("Binary representation: 0\n");
        printf("Number of 1s: 0\n");
        printf("Number of 0s: 1\n");
        printf("Longest consecutive 1s: 0\n");
        return 0;
    }

    temp = number;

    while (temp > 0) {
        int bit = temp % 2;
        binary[index++] = bit;

        if (bit == 1) {
            ones++;
            currentOnes++;

            if (currentOnes > longestOnes) {
                longestOnes = currentOnes;
            }
        } else {
            zeros++;
            currentOnes = 0;
        }

        temp /= 2;
    }

    printf("Binary representation: ");

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\nNumber of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Longest consecutive 1s: %d\n", longestOnes);

    return 0;
}