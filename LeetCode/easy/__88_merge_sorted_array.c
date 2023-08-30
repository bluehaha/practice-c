#include <stdio.h>
#include "help.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1,
        j = n-1,
        ptr = m+n-1;

    while (i >= 0 && j >= 0) {
        /* printf("[%d, %d] ", nums1[i], nums2[j]); */
        if (nums1[i] > nums2[j]) {
            /* printf("%d ", nums1[i]); */
            nums1[ptr] = nums1[i];
            i--;
        } else {
            /* printf("%d ", nums1[j]); */
            nums1[ptr] = nums2[j];
            j--;
        }
        /* printf("%d ", ptr); */
        ptr--;
    }

    while (j >= 0) {
        nums1[ptr] = nums2[j];
        j--;
        ptr--;
    }
}


int main() {
    int nums1[] = {};
    int nums2[] = {1};

    merge(nums1, 1, 0, nums2, 1, 1);

    print_array(nums1, 1);
}
