#include <stdio.h>
#include <stdbool.h>

#define N 4

// M[i][j] = 1 means person i knows person j
// Celebrity conditions:
// 1. Everyone knows the celebrity: M[i][celeb] == 1 for all i != celeb
// 2. The celebrity knows nobody: M[celeb][j] == 0 for all j
int M[N][N] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}, // Person 2 knows nobody and is known by 0, 1, 3
    {0, 0, 1, 0}
};

// Helper function to check if person 'a' knows person 'b'
bool knows(int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(int n) {
    int candidate = 0;

    // Step 1: Find a potential candidate using elimination
    for (int i = 1; i < n; i++) {
        if (knows(candidate, i)) {
            // If candidate knows i, candidate cannot be a celebrity
            candidate = i;
        }
        // If candidate does not know i, i cannot be a celebrity (so candidate remains)
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate must not know i, and i must know candidate
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1; // No celebrity exists
            }
        }
    }

    return candidate;
}

int main(void) {
    int celeb = findCelebrity(N);

    if (celeb == -1) {
        printf("No celebrity found.\n");
    } else {
        printf("Celebrity is person %d\n", celeb);
    }

    return 0;
}