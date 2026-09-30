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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* prev = nullptr;

        int carry = 0;
        while (curr1 && curr2) {
            int currSum = curr1->val + curr2->val + carry;
            curr1->val = currSum % 10;
            carry = currSum / 10;
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            int currSum = curr1->val + carry;
            curr1->val = currSum % 10;
            carry = currSum / 10;
            prev = curr1;
            curr1 = curr1->next;
        }

        if (curr2) {
            prev->next = curr2;
            curr1 = curr2;
            while (curr1) {
                int currSum = curr1->val + carry;
                curr1->val = currSum % 10;
                carry = currSum / 10;
                prev = curr1;
                curr1 = curr1->next;
            }
        }

        if (carry != 0) {
            prev->next = new ListNode(1);
        }

        return head;
    }
};
