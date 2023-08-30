#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int majorityElement(int* nums, int numsSize) {
    int min =nums[0], max = min;
    int i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
        if (nums[i] > max)
            max = nums[i];
    }

    int mapSize = max - min + 1;
    int map[mapSize];
    memset(map, 0, sizeof(int) * mapSize);

    for (i = 0; i < numsSize; i++) {
        map[nums[i] - min]++;

        if (map[nums[i] - min] > numsSize / 2)
            return nums[i];
    }

    return 0;
}

int main() {
    int nums[] = {2,2,1,1,1,2,2};
    int numsSize = 7;
    int result = majorityElement(nums, numsSize);
    printf("%d\n", result);
    return 0;
}
