#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    /* for (int i = 0; i < intervalsSize; i++) { */
    /*     printf("%d %d\n", intervals[i][0], intervals[i][1]); */
    /* } */

    int ** result = (int **) malloc(sizeof(int *) * intervalsSize);
    int index = 0;

    result[index] = (int *) malloc(sizeof(int) * 2);
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (result[index][1] >= intervals[i][0]) {
            result[index][1] = result[index][1] > intervals[i][1] ? result[index][1] : intervals[i][1];
        } else {
            index++;
            result[index] = (int *) malloc(sizeof(int) * 2);
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
        }
    }
    *returnSize = index + 1;
    *returnColumnSizes = (int *) malloc(sizeof(int *) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}

int main() {
    int row1[] = {1,3};
    int row2[] = {2,6};
    int row3[] = {8,10};
    int row4[] = {15,18};
    int *matrix[] = {row1, row2, row3, row4};
    /* int *matrix[] = {row1, row2}; */
    int matrixSize = sizeof(matrix)/sizeof(matrix[0]);
    int matrixColSize[] = {2,2,2,2};
    int returnSize;
    int *returnColumnSizes;
    int **result = merge(matrix, matrixSize, matrixColSize, &returnSize, &returnColumnSizes);
    int i, j;
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
