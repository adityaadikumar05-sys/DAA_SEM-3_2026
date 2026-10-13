#include <stdio.h>

int main() {
    int n = 5;
    
    int g[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {0};
    int edges = 0, cost = 0;

    visited[0] = 1;

    while (edges < n - 1) {
        int min = 999;
        int a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && g[i][j] != 0) {
                        if (g[i][j] < min) {
                            min = g[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d = %d\n", a, b, min);

        visited[b] = 1;
        cost += min;
        edges++;
    }

    printf("Minimum Cost = %d", cost);

    return 0;
}