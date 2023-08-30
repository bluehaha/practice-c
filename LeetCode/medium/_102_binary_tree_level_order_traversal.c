#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../help.h"

struct QueueNode {
    struct TreeNode * treeNode;
    struct QueueNode * next;
};

struct Queue {
    struct QueueNode * head;
    struct QueueNode * tail;
    int size;
};

void enqueue(struct Queue *q, struct TreeNode * treeNode) {
    if (treeNode == NULL)
        return;

    struct QueueNode * node = malloc(sizeof(struct QueueNode));
    node->treeNode = treeNode;
    node->next = NULL;

    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
        q->size = 1;
    } else {
        q->tail->next = node;
        q->tail = node;
        q->size++;
    }
}

struct QueueNode * dequeue(struct Queue *q) {
    if (q->head == NULL)
        return NULL;

    struct QueueNode *tmp = q->head;
    q->head = q->head->next;
    q->size--;
    return tmp;
}

int findHeight(struct TreeNode * root) {
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct Queue * q = malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    struct QueueNode * queueNode;
    int i,
        size,
        height = findHeight(root);
    int * oneLevel;
    int ** result = (int **) malloc(sizeof(int *) * height);

    enqueue(q, root);
    *returnSize = 0;
    *returnColumnSizes= (int *) malloc(sizeof(int) * height);

    while(q->size != 0) {
        result[*returnSize] = (int *) malloc(sizeof(int) * q->size);
        size = q->size;
        (*returnColumnSizes)[*returnSize] = size;
        for (i = 0; i < size; i++) {
            queueNode = dequeue(q);
            result[*returnSize][i] = queueNode->treeNode->val;
            enqueue(q, queueNode->treeNode->left);
            enqueue(q, queueNode->treeNode->right);
        }
        (*returnSize)++;
    }

    return result;
}

int main() {
    int nums[] = {3,9,20,0,0,15,7};
    struct TreeNode * root = create_tree(nums, 7);
    print_tree(root);
    printf("\n");
    int returnSize;
    int * returnColumnSizes;
    int ** result = levelOrder(root, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
