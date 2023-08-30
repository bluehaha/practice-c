#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int doSearch(int* nums, int start, int end, int target) {
    if (start == end && nums[start] == target)
        return start;
    if (start >= end)
        return -1;

    int mid = (start + end) / 2;
    if (nums[mid] == target)
        return mid;

    if (nums[mid] >= nums[start]) {
        if (target >= nums[start] && target < nums[mid])
            return doSearch(nums, start, mid - 1, target);
        else
            return doSearch(nums, mid + 1, end, target);
    } else {
        if (target <= nums[end] && target > nums[mid])
            return doSearch(nums, mid + 1, end, target);
        else
            return doSearch(nums, start, mid - 1, target);
    }
}

int search(int* nums, int numsSize, int target){
    return doSearch(nums, 0, numsSize - 1, target);
}

int main() {
    int nums[] = {1,3};
    int numsSize = 2;
    int target = 1;

    printf("%d\n", search(nums, numsSize, target));
}
