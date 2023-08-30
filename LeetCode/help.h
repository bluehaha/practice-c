void print_array(int* nums, int numsSize);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_tree(int* nums, int numsSize);

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_tree(struct TreeNode* root);

void print_linked_list(struct ListNode* head);

struct ListNode* create_linked_list(int *nums, int numsSize);
