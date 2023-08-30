#include <stdio.h>
#include "stdlib.h"

int removeDuplicates(int* nums, int numsSize) {
    int ptr = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[ptr] = nums[i];
            ptr++;
        }
    }
    return ptr;
}

int main() {
    int a[] = {1};
    int k = removeDuplicates(a, sizeof(a)/sizeof(int));

    for (int i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }
}
