#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            char letter = 'A' + ((row + column) % 26);
            printf("%c ", letter);
        }

        printf("\n");
    }

    return 0;
}