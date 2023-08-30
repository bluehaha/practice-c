#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../help.h"

void inorderTraversal(struct TreeNode* treeNode, struct ListNode ** head, struct ListNode ** currListNode) {
    if (treeNode == NULL)
        return;

    inorderTraversal(treeNode->left, head, currListNode);

    struct ListNode * listNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    listNode->val = treeNode->val;
    listNode->next = NULL;

    if (*head == NULL)
        *head = listNode;

    if (*currListNode != NULL) {
        (*currListNode)->next = listNode;
    }
    *currListNode = listNode;

    inorderTraversal(treeNode->right, head, currListNode);
}

bool isValidBST(struct TreeNode* root) {
    struct ListNode * head = NULL;
    struct ListNode * currListNode = NULL;
    inorderTraversal(root, &head, &currListNode);

    currListNode = head;
    int pre = currListNode->val;
    currListNode = currListNode->next;

    while(currListNode != NULL) {
        if (pre >= currListNode->val)
            return false;

        pre = currListNode->val;
        currListNode = currListNode->next;
    }
    return true;
}


int main() {
    int nums[] = {4,1,3};
    struct TreeNode * root = create_tree(nums, 3);
    print_tree(root);
    printf("\n");
    printf("%d\n", isValidBST(root));
}
