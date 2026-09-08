/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        int listSize = 0;
        while (curr) {
            listSize++;
            curr = curr->next;
        }

        int delIndex = listSize - n;
        int i = 0;
        curr = head;
        ListNode *prev = nullptr;
        while (i != delIndex) {
            i++;
            prev = curr;
            curr = curr->next;
        }

        if (prev != nullptr) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        return head;
    }
};
