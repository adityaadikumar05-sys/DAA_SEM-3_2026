/**5. Write a program to multiply two matrices. Before multiplication, verify whether the given matrices are
compatible.**/

#include <stdio.h>

#define R1 2
#define C1 3
#define R2 3
#define C2 2

void multiplyMatrices(int mat1[][C1], int mat2[][C2], int res[][C2]) {
    printf("Multiplying matrices...\n");
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int rows, int cols, int mat[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (C1 != R2) {
        printf("Matrices are not compatible for multiplication.\n");
        return 1;
    }

    int mat1[R1][C1] = {{1, 2, 3},
                        {4, 5, 6}};

    int mat2[R2][C2] = {{7, 8},
                        {9, 10},
                        {11, 12}};

    int res[R1][C2];

    multiplyMatrices(mat1, mat2, res);

    printf("Resultant matrix:\n");
    displayMatrix(R1, C2, res);

    return 0;
}
