#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../help.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 0;
    struct ListNode* tmp = head, *prev = NULL;

    while (tmp != NULL) {
        tmp = tmp->next;
        length++;
    }

    if (n == length) {
        head = head->next;
        return head;
    }

    n = length - n;
    tmp = head;
    while (n > 0) {
        prev = tmp;
        tmp = tmp->next;
        n--;
    }

    prev->next = tmp->next;

    return head;
}

int main() {
    int nums[] = {1,2};
    struct ListNode* l1 = create_linked_list(nums, 2);
    struct ListNode* l2 = removeNthFromEnd(l1, 1);
    print_linked_list(l2);

    return 0;
}
