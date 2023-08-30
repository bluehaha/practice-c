#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int rightDepth = maxDepth(root->right);
    int leftDepth = maxDepth(root->left);
    int max = rightDepth > leftDepth ? rightDepth : leftDepth;

    return 1 + max;
}

int main() {
    int nums[] = {1,2,3,4};
    struct TreeNode* root = create_tree(nums, 4);
    printf("%d\n", maxDepth(root));
    return 0;
}
