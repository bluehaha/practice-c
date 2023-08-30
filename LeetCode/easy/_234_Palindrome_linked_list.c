#include <stdbool.h>
#include <stdio.h>
#include "help.h"

int find_length(struct ListNode* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* reverse(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* curr = head;
    struct ListNode* next = curr->next;
    struct ListNode* tmp;
    head->next = NULL;

    while(next != NULL) {
        tmp = next->next;
        next->next = curr;
        curr = next;
        next = tmp;
    }

    return curr;
}

bool isPalindrome(struct ListNode* head) {
    int length = find_length(head);
    int skip = length / 2 + length % 2;
    struct ListNode* head2 = head;
    while(skip > 0) {
        head2 = head2->next;
        skip--;
    }
    head2 = reverse(head2);

    while(head2 != NULL) {
        if (head->val != head2->val)
            return false;

        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main() {
    int nums[] = {3};
    struct ListNode *head = create_linked_list(nums, 1);
    printf("%d\n", isPalindrome(head));
}
