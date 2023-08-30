#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int* inorderTraversal(TreeNode* root, int* returnSize) {
    if (root == NULL) {
        return NULL;
    }

	TreeNode* stack[100];
    TreeNode* currentNode;
    int* order = (int*) malloc(sizeof(int) * 100);

    stack[0] = root;
    int ptr = 0;
    *returnSize = 0;

    while (ptr >= 0) {
        currentNode = stack[ptr];

        if (currentNode->left != NULL) {
            ptr++;
            stack[ptr] = currentNode->left;
            /* currentNode->left = NULL; */
            continue;
        }

        order[*returnSize] = currentNode->val;
        *returnSize = *returnSize + 1;
        ptr--;

        if (currentNode->right != NULL) {
            ptr++;
            stack[ptr] = currentNode->right;
            /* currentNode->right = NULL; */
        }
    }

    return order;
}

int main() {
    int nums[] = {1, 2, 3};
    int returnSize = -1;
    int *order;
    TreeNode one = {1, NULL, NULL};
    TreeNode two = {2, NULL, NULL};
    TreeNode three = {3, NULL, NULL};
    one.right = &two;
    two.left = &three;

    order = inorderTraversal(&one, &returnSize);
    printf("returnSize %d\n", returnSize);

    print_array(order, returnSize);
}
