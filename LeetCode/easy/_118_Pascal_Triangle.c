#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int*) malloc(sizeof(int) * numRows);
    int** result = (int**) malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        result[i] = (int*) malloc(sizeof(int) * (i+1));
        result[i][0] = 1;
        result[i][i] = 1;

        (*returnColumnSizes)[i] = i+1;

        if (i >= 2) {
            for (int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
    }
    return result;
}

int main() {
    int returnSize;
    int* returnColumnSizes;
    int** result = generate(4, &returnSize, &returnColumnSizes);

    printf("returnSize: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("returnColumnSizes[%d]: %d\n", i, returnColumnSizes[i]);

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
