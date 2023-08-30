#include <stdio.h>
#include <string.h>
#include "stdlib.h"
/**
 ** Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode *list, *ptr;
    if (list1->val < list2->val) {
        list = ptr = list1;
        list1 = list1->next;
    } else {
        list = ptr = list2;
        list2 = list2->next;
    }

    while(list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            ptr = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            ptr = list2;
            list2 = list2->next;
        }
    }

    if (list1 == NULL) {
        ptr->next = list2;
    } else {
        ptr->next = list1;
    }

    return list;
}

struct ListNode* createList(int* arr, int size) {
    struct ListNode *start = malloc(sizeof(struct ListNode));
    start->val = arr[0];
    start->next = NULL;
    struct ListNode *curr, *prev = start;

    for (int i = 1; i < size; i++) {
        curr = malloc(sizeof(struct ListNode));
        curr->val = arr[i];
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
    }

    return start;
}

void showList(struct ListNode* list) {
    do {
        printf("%d ", list->val);
        list = list->next;
    } while (list != NULL);
    printf("\n");
}

int main() {
    int a[] = { 1,2,4 };
    int b[] = {};
    struct ListNode* list1 = createList(a, sizeof(a)/sizeof(int));
    struct ListNode* list2 = createList(b, sizeof(b)/sizeof(int));

    /* printf("%d %d", list1->val, list1->next->val); */
    showList(mergeTwoLists(list1, list2));
    /* showList(list1); */
}
