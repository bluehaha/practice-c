#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../help.h"

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode * queue[2000], * node;
    queue[0] = root;
    int front = 0,
        end = 1,
        level = 0,
        order = 0,
        i,
        size;
    int ** result = (int **) malloc(sizeof(int *) * 2000);
    *returnColumnSizes = (int *) malloc(sizeof(int) * 2000);

    while (front < end) {
        size = end - front;
        result[level] = (int *) malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        if (order == 0) {
            for (i = 0; i < size; i++) {
                result[level][i] = queue[front + i]->val;
            }

        } else {
            for (i = 0; i < size; i++) {
                result[level][i] = queue[end - i - 1]->val;
            }
        }

        for (i = 0; i < size; i++) {
            node = queue[front + i];

            if (node->left != NULL)
                queue[end++] = node->left;
            if (node->right != NULL)
                queue[end++] = node->right;
        }

        front += size;
        level++;
        order = order ^ 1;
    }

    *returnSize = level;

    return result;
}

int main() {
    int nums[] = {3,9,20,0,0,15,7};
    struct TreeNode * root = create_tree(nums, 7);
    print_tree(root);
    printf("\n");
    int returnSize;
    int * returnColumnSizes;
    int ** result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
