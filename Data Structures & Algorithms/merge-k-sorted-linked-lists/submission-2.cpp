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
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1 == nullptr) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listSize = lists.size();
        if (listSize == 0) {
            return nullptr;
        }

        if (listSize == 1) {
            return lists[0];
        }

        if (listSize == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int midIndex = listSize / 2;
        vector<ListNode*> vec1(lists.begin(), lists.begin() + midIndex);
        vector<ListNode*> vec2(lists.begin() + midIndex, lists.end());
        ListNode* list1 = mergeKLists(vec1);
        ListNode* list2 = mergeKLists(vec2);
        return mergeTwoLists(list1, list2);
    }
};
