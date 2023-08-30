#include <stdio.h>
#include <stdlib.h>
#include "./../help.h"

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){


}

int main() {
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};
    int preorderSize = 5;
    int inorderSize = 5;
    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);
    print_tree(root);
    return 0;
}
