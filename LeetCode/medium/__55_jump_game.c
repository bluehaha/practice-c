#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
    int max = nums[0], tmpMax;

    for (int i = 0; i <= max; i++) {
        if (max >= numsSize - 1) {
            return true;
        }
        tmpMax = i + nums[i];
        if (tmpMax > max) {
            max = tmpMax;
        }
    }

    return false;
}

int main () {
    int nums[] = {2,3,1,1,4};
    int numsSize = 5;
    printf("%d\n", canJump(nums, numsSize));

    int nums2[] = {3,2,1,0,4};
    int numsSize2 = 5;
    printf("%d\n", canJump(nums2, numsSize2));

    return 0;
}
