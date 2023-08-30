#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doPermute(int *nums, int numsSize, int** premutation, int rowOffset, int colOffset) {
    int size = 1, tmp, row;

    if (numsSize == 1) {
        premutation[rowOffset][colOffset] = nums[0];
        return;
    }

    for (int i = 1; i < numsSize; i++) {
        size *= i;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < size; j++) {
            row = rowOffset + i*size+j;
            premutation[row][colOffset] = nums[i];
        }
        tmp = nums[numsSize-1];
        nums[numsSize-1] = nums[i];
        nums[i] = tmp;

        doPermute(nums, numsSize-1, premutation, rowOffset+i*size, colOffset+1);

        tmp = nums[i];
        nums[i] = nums[numsSize-1];
        nums[numsSize-1] = tmp;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int i;
    *returnSize = 1;

    for (i = 1; i <= numsSize; i++) {
        *returnSize *= i;
    }

    int** premutation = (int **) malloc(sizeof(int *) * *returnSize);
    *returnColumnSizes = (int *) malloc(sizeof(int) * *returnSize);
    for (i = 0; i < *returnSize; i++) {
        premutation[i] = (int *) malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }

    doPermute(nums, numsSize, premutation, 0, 0);

    return premutation;
}

int main() {
    int nums[] = {1, 2, 3};
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = permute(nums, 3, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
