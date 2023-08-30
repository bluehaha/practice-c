#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int missingNumber(int* nums, int numsSize) {
    int* tmp = (int*) malloc(sizeof(int) * (numsSize + 1));
    int i;

    memset(tmp, 0, sizeof(int) * (numsSize + 1));

    for (i = 0; i < numsSize; i++) {
        tmp[nums[i]] = 1;
    }

    for (i = 0; i <= numsSize; i++) {
        if (tmp[i] == 0)
            return i;
    }

    return i;
}

int main() {
    int nums[] = {3,0,1};
    /* int nums[] = {3, 1, 2}; */

    int result = missingNumber(nums, 3);

    printf("%d", result);
}
