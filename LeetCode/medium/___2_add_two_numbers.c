#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./../help.h"

int getLength(struct ListNode* l) {
    int length = 0;
    while (l != NULL) {
        length++;
        l = l->next;
    }
    return length;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int length1 = getLength(l1);
    int length2 = getLength(l2);
    struct ListNode* tmp , *head;

    if (length1 < length2) {
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    head = l1;

    int carry = 0, value;
    while (l1 != NULL) {
        value = l1->val + (l2 != NULL ? l2->val : 0) + carry;
        carry = value / 10;
        l1->val = value % 10;

        tmp = l1;
        l1 = l1->next;
        l2 = l2 != NULL ? l2->next : NULL;
    }

    if (carry) {
        tmp->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmp->next->val = carry;
        tmp->next->next = NULL;
    }

    return head;
}

int main() {
    int nums1[] = {1};
    int nums2[] = {9};

    struct ListNode* l1 = create_linked_list(nums1, 1);
    struct ListNode* l2 = create_linked_list(nums2, 1);

    struct ListNode* l3 = addTwoNumbers(l1, l2);
    print_linked_list(l3);

    return 0;
}
