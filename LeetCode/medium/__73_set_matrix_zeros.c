#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setZeroes (int** matrix, int matrixSize, int* matrixColSize) {
    int * zeroRows = malloc(sizeof(int) * matrixSize);
    int * zeroCols = malloc(sizeof(int) * matrixColSize[0]);
    memset(zeroRows, 0, sizeof(int) * matrixSize);
    memset(zeroCols, 0, sizeof(int) * matrixColSize[0]);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (zeroRows[i] == 1) {
            for (int j = 0; j < matrixColSize[0]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < matrixColSize[0]; j++) {
        if (zeroCols[j] == 1) {
            for (int i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int row1[] = {0,1,2,0};
    int row2[] = {3,4,5,2};
    int row3[] = {1,3,1,5};
    int *matrix[] = {row1, row2, row3};
    int matrixSize = sizeof(matrix)/sizeof(matrix[0]);
    int matrixColSize[] = {4,4,4};
    setZeroes(matrix, matrixSize, matrixColSize);
    int i, j;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
