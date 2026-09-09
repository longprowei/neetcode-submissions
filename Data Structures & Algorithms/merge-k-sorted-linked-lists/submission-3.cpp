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
    ListNode *mergeListsRange(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        if (l == r) {
            return lists[l];
        }

        int mid = l + (r - l) / 2;
        ListNode *list1 = mergeListsRange(lists, l, mid);
        ListNode *list2 = mergeListsRange(lists, mid + 1, r);
        return mergeTwoLists(list1, list2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeListsRange(lists, 0, lists.size() - 1);
    }
};
