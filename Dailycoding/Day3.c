#include <stdio.h>

int main(void) {
    int temperatures[] = {10, 12, 15, 14, 16, 18, 20};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    int current = 1;
    int longest = 1;

    for (int i = 1; i < n; i++) {
        if (temperatures[i] > temperatures[i - 1])
            current++;
        else
            current = 1;

        if (current > longest)
            longest = current;
    }

    printf("%d\n", longest);
    return 0;
}