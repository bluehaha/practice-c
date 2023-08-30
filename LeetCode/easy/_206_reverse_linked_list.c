#include <stdio.h>
#include "help.h"

struct ListNode* doReverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* revertSubListTail = doReverseList(head->next);
    revertSubListTail->next = head;
    return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* tail, *tmp = head;
    do {
        tail = tmp;
        tmp = tmp->next;
    } while (tmp != NULL);

    doReverseList(head);
    head->next = NULL;

    return tail;
}

int main() {
    int nums[] = {1,2,3};

    struct ListNode* list = create_linked_list(nums, 3);

    list = reverseList(list);

    print_linked_list(list);
}
