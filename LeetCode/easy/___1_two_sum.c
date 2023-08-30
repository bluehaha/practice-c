#include "stdio.h"
#include "stdlib.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int* a = (int*) malloc(sizeof(int) * 2);

    for (i = 0; i < numsSize-1; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                break;
            }
        }
    }

    return a;
}

int main() {
    int nums[] = { 3,2,4,5 }, target = 9;
    int returnSize[2];
    int* result = twoSum(nums, 4, target, returnSize);

    printf("%d %d\n", result[0], result[1]);
}
