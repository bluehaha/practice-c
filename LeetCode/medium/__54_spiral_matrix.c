#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int ** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int width = matrixColSize[0],
        height = matrixSize;
    *returnSize = height * width;
    int *result = malloc(*returnSize * sizeof(int));
    int i,
        index=0,
        top = 0,
        buttom = height - 1,
        left = 0,
        right = width - 1;
    printf("width: %d, height: %d top: %d, buttom: %d, left: %d, right: %d\n", width, height, top, buttom, left, right);

    while (top <= buttom && left <= right) {
        if (top == buttom) {
            for (i = left; i <= right; i++) {
                result[index++] = matrix[top][i];
            }
            break;
        }
        if (left == right) {
            for (i = top; i <= buttom; i++) {
                result[index++] = matrix[i][left];
            }
            break;
        }

        for (i = left; i < right; i++) {
            result[index++] = matrix[top][i];
        }
        for (i = top; i < buttom; i++) {
            result[index++] = matrix[i][right];
        }
        for (i = right; i > left; i--) {
            result[index++] = matrix[buttom][i];
        }
        for (i = buttom; i > top; i--) {
            result[index++] = matrix[i][left];
        }
        top++;
        buttom--;
        left++;
        right--;
    }

    return result;
}

int main() {
    int row1[] = {6,9,7};
    /* int row2[] = {5,6,7,8}; */
    /* int row3[] = {9,10,11,12}; */
    int *matrix[] = {row1};
    /* int *matrix[] = {row1, row2, row3}; */
    int matrixSize = 1;
    int matrixColSize[] = {3};
    int returnSize = 0;
    int *result = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
