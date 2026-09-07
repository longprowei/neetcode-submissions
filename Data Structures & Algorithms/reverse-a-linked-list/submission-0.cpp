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
    ListNode* reverseList(ListNode* head) {
        vector<int> nodeVals;
        ListNode *curr = head;
        while(curr) {
            nodeVals.push_back(curr->val);
            curr = curr->next;
        }

        if (nodeVals.size() > 0) {
            ListNode *newList = new ListNode(nodeVals[nodeVals.size() - 1]);
            ListNode *curr = newList->next;
            ListNode *pred = newList;
            for (int i = nodeVals.size() - 2; i >= 0; i--) {
                curr = new ListNode(nodeVals[i]);
                pred->next = curr;
                pred = curr;
                curr = curr->next;
            }
            return newList;
        } else {
            return nullptr;
        }
    }
};
