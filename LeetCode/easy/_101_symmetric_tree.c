#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "help.h"

bool compare(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left != NULL && right != NULL && left->val == right->val) {
        return true;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }

    if ((root->left == NULL || root->right == NULL)
        || root->left->val != root->right->val
    ) {
        return false;
    }

    struct TreeNode * nodes[1024];
    struct TreeNode * nodes2[1024];

    int head = 0, tail = 1;
    nodes[head] = root->left;
    nodes[tail] = root->right;

    while (tail > 0) {
        int leftPtr = head, rightPtr = tail;
        while (leftPtr < rightPtr) {
            if (! compare(nodes[leftPtr]->left, nodes[rightPtr]->right)
                || ! compare( nodes[leftPtr]->right, nodes[rightPtr]->left)
            ) {
                return false;
            }
            leftPtr++;
            rightPtr--;
        }
        int newTail = -1;
        for (int i = head; i <= tail; i++) {
            if (nodes[i]->left != NULL) {
                nodes2[++newTail] = nodes[i]->left;
            }
            if (nodes[i]->right != NULL) {
                nodes2[++newTail] = nodes[i]->right;
            }
        }
        if (newTail < 0) {
            break;
        }
        memcpy(nodes, nodes2, sizeof(struct TreeNode*) * (newTail+1));
        tail = newTail;
    }

    return true;
}

int main() {
    int nums[] = {1,2};
    struct TreeNode* root = create_tree(nums, 2);
    printf("%d\n", isSymmetric(root));
    return 0;
}
