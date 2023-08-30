#include <stdio.h>
#include <stdlib.h>
#include "help.h"

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    if (numsSize == 1) {
        root->val = nums[0];
        return root;
    }

    int mid = numsSize / 2;
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums+mid+1, numsSize-mid-1);

    return root;
}

int main() {
    int nums[] = {-10,-5,0,3,9};
    struct TreeNode* root = sortedArrayToBST(nums, 5);

    print_tree(root);

    return 0;
}
