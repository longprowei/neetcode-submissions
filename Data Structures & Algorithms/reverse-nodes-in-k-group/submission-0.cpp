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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;

        while (curr) {
            n++;
            curr = curr->next;
        }

        ListNode* newHead = nullptr;

        int groups = n / k;
        ListNode* prev = nullptr;
        curr = head;
        ListNode* groupFirst = curr; // 
        ListNode* groupLast = prev; // the last node from last group
        for (int i = 0; i < groups; i++) {
            for (int j = 0; j < k; j++) {
                ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            groupFirst->next = curr;
            if (groupLast) {
                groupLast->next = prev;
            }
            groupLast = groupFirst;
            groupFirst = groupFirst->next;
            

            if (i == 0) {
                newHead = prev;
            }
        }

        return newHead ? newHead : head;
    }
};
