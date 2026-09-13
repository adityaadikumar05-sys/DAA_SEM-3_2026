#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int totalElements = matrixSize * matrixColSize[0];
    int* result = (int*)malloc(totalElements * sizeof(int));
    *returnSize = totalElements;

    int top = 0;
    int bottom = matrixSize - 1;
    int left = 0;
    int right = matrixColSize[0] - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        
        for (int col = left; col <= right; col++) {
            result[idx++] = matrix[top][col];
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            result[idx++] = matrix[row][right];
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[idx++] = matrix[bottom][col];
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[idx++] = matrix[row][left];
            }
            left++;
        }
    }

    return result;
}

int main() {
    int m = 3, n = 4;
    int data[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    int* matrix[3];
    int colSize[3];
    for (int i = 0; i < m; i++) {
        matrix[i] = data[i];
        colSize[i] = n;
    }

    int returnSize = 0;
    int* spiral = spiralOrder(matrix, m, colSize, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", spiral[i], (i < returnSize - 1) ? ", " : "");
    }
    printf("]\n");

    free(spiral);
    return 0;
}