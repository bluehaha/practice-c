#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = (int **) malloc(sizeof(int *) * 1000);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    int i, left, right;
    for (i = 0; i < numsSize-2; i++) {
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        left = i+1;
        right = numsSize-1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] == 0) {
                result[*returnSize] = (int *) malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;
                do {
                    left++;
                } while (nums[left-1] == nums[left] && left < right);
                do {
                    right--;
                } while (nums[right+1] == nums[right] && right > left);
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}

int main() {
    int nums[] = {-2,0,0,2,2};
    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, 5, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
