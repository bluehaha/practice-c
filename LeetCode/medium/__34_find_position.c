#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../help.h"

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int * result = malloc(sizeof(int) * 2);

    int left = 0,
        right = numsSize - 1,
        index = -1,
        mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (target == nums[mid]) {
            index = mid;
            break;
        }

        if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    left = index;
    right = index;

    while (left > 0) {
        if (nums[left-1] == target)
            left--;
        else
            break;
    }
    while (right < numsSize - 1 && right != -1) {
        if (nums[right+1] == target)
            right++;
        else
            break;
    }

    result[0] = left;
    result[1] = right;

    return result;
}

int main() {
    int nums[] = {5,7,7,8,8,10};
    int numsSize = 6;
    int target = 8;
    int returnSize;

    int* result = searchRange(nums, numsSize, target, &returnSize);
    print_array(result, returnSize);

    result = searchRange(nums, numsSize, 6, &returnSize);
    print_array(result, returnSize);

    printf("\n");
}
