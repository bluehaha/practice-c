#include <stdio.h>
#include <stdlib.h>
#include "help.h"

void print_array(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if (i < numsSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

struct TreeNode* create_tree(int* nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    struct TreeNode* nodes = malloc(sizeof(struct TreeNode) * numsSize + 1);
    int i = 0;
    for (i = 1; i <= numsSize; i++) {
        nodes[i].val = nums[i-1];
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }

    for (i = 1; i <= numsSize/2; i++) {
        /* if (nodes[i].val == NULL) { */
        /*     continue; */
        /* } */
        nodes[i].left = &nodes[2*i];
        nodes[i].right = &nodes[2*i+1];
    }

    return &nodes[1];
}

void print_tree(struct TreeNode* root) {
    if (root == NULL) {
        printf("null");
        return;
    }

    printf("%d", root->val);
    if (root->left != NULL || root->right != NULL) {
        printf("(");
        print_tree(root->left);
        printf(", ");
        print_tree(root->right);
        printf(")");
    }
}

void print_linked_list(struct ListNode* head) {
    if (head == NULL) {
        printf("null");
        return;
    }

    printf("%d", head->val);
    if (head->next != NULL) {
        printf(" -> ");
        print_linked_list(head->next);
    }
}

struct ListNode* create_linked_list(int *nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    struct ListNode* nodes = malloc(sizeof(struct ListNode) * numsSize);
    int i;

    for (i = 0; i < numsSize; i++) {
        nodes[i].val = nums[i];
        nodes[i].next = &nodes[i+1];
    }
    nodes[i-1].next = NULL;

    return nodes;
}
