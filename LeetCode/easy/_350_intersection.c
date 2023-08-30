#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hash1[1001] = {0};
    int hash2[1001] = {0};
    int i, index=0;
    *returnSize = 0;

    for (i = 0; i < nums1Size; i++) {
        hash1[nums1[i]]++;
    }

    for (i = 0; i < nums2Size; i++) {
        if (hash1[nums2[i]] == 0) {
            continue;
        }

        hash1[nums2[i]]--;
        hash2[nums2[i]]++;
        *returnSize += 1;
    }

    int* intersect = malloc(*returnSize * sizeof(int));

    for (i = 0; i < 1001; i++) {
        while (hash2[i] > 0) {
            intersect[index] = i;
            hash2[i]--;
            index++;
        }
    }

    return intersect;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize = 0;
    int* result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    print_array(result, returnSize);

    return 0;
}
