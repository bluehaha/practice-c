#include <stdio.h>
#include <stdlib.h>
#include "help.h"

void moveZeroes(int* nums, int numsSize) {
    int* tmpArr = malloc(sizeof(int) * numsSize);
    int i, head = 0, tail = numsSize-1;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            tmpArr[tail] = 0;
            tail--;
        } else {
            tmpArr[head] = nums[i];
            head++;
        }
    }
    for (i = 0; i < numsSize; i++) {
        nums[i] = tmpArr[i];
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = 5;

    moveZeroes(nums, numsSize);

    print_array(nums, numsSize);
}
