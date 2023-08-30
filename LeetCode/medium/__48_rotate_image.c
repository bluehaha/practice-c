#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 1)
        return;

    int tmpSize = sizeof(int) * (matrixSize-1);
    int* tmp = malloc(tmpSize);

    int step = 0, i, boundary;

    while (matrixSize > step*2+1) {
        memcpy(tmp, matrix[step], tmpSize);

        boundary = matrixSize - 2*step - 1;

        for (i = 0; i < boundary; i++) {
            matrix[step][i+step] = matrix[matrixSize-1-step-i][step];
            matrix[matrixSize-1-step-i][step] = matrix[matrixSize-1-step][matrixSize-1-step-i];
            matrix[matrixSize-1-step][matrixSize-1-step-i] = matrix[step+i][matrixSize-1-step];
            matrix[step+i][matrixSize-1-step] = tmp[step+i];
        }

        step++;
    }
}

int main() {
    int row1[] = {5,1,9,11},
        row2[] = {2,4,8,10},
        row3[] = {13,3,6,7},
        row4[] = {15,14,12,16},
        colSize[] = {4,4,4,4};

    int *matrix[] = { row1, row2, row3, row4 };

    rotate(matrix, 4, colSize);

    for (int i = 0; i < 4; i++) {
        printf("%d %d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
    }
}
