#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
    int max, sum = 0, i;

    max = nums[0];

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];

        if (sum > max)
            max = sum;

        if (sum < 0)
            sum = 0;
    }

    return max;
}

int main() {
    int nums[] = {-2, -1};
    int result = maxSubArray(nums, 2);
    printf("%d\n", result);
}
