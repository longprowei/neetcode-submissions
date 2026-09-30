/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> addressMap;

        Node dummyNode(0);
        Node* curr = &dummyNode;
        Node* currOrigin = head;
        while (currOrigin) {
            curr->next = new Node(currOrigin->val);
            addressMap[currOrigin] = curr->next;
            currOrigin = currOrigin->next;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            addressMap[curr]->random = curr->random ? addressMap[curr->random] : nullptr;
            curr = curr->next;
        }

        return dummyNode.next;
    }
};
