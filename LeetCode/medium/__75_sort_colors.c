#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize){
    int count[3] = {0};

    for (int i = 0; i < numsSize; i++) {
        switch (nums[i]) {
            case 0:
                count[0]++;
                break;
            case 1:
                count[1]++;
                break;
            case 2:
                count[2]++;
                break;
        }
    }
    for (int i = 0; i < count[0]; i++) {
        nums[i] = 0;
    }
    for (int i = count[0]; i < count[0]+count[1]; i++) {
        nums[i] = 1;
    }
    for (int i = count[0]+count[1]; i < numsSize; i++) {
        nums[i] = 2;
    }
}

int main() {
    int nums[] = {2,0,2,1,1,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    sortColors(nums, numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
