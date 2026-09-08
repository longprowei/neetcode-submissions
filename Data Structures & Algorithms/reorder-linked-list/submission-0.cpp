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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode *curr = head;

        while (curr) {
            dq.push_back(curr);
            curr = curr->next;
        }

        ListNode dummyNode(0);
        curr = &dummyNode;
        while (dq.size() >= 2) {
            curr->next = dq.front();
            curr = curr->next;
            dq.pop_front();
            curr->next = dq.back();
            curr = curr->next;
            dq.pop_back();
        }

        if (dq.size()) {
            curr->next = dq.front();
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};
