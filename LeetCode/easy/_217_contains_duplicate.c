#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int hash(int key, int inputSize){
    return abs(key) % inputSize;
}

bool containsDuplicate(int* nums, int numsSize){
    int hashTableSize = 2 * numsSize;
    int *hashTable = (int *) malloc(hashTableSize * sizeof( int ));

    for (int i = 0; i < numsSize; i++) {
        if (hashTable[hash(nums[i], hashTableSize)] == nums[i]) {
            return true;
        } else {
            hashTable[hash(nums[i], hashTableSize)] = nums[i];
        }
    }

    return false;
}

int main() {
    int nums[] = {3,1,3};
    /* int nums[] = {3, 1, 2}; */

    bool result = containsDuplicate(nums, 3);

    printf("%d", result);
    /* print_array(nums, 12); */
}
