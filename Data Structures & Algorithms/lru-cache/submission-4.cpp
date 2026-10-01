struct ListNode {
    ListNode *next;
    ListNode *prev;
    int val;
    int key;
    ListNode(int val, int key) : 
        next(nullptr), prev(nullptr), val(val), key(key) {}
};

class LRUCache {
private:
    ListNode *head;
    ListNode *tail;
    int capacity;
    unordered_map<int, ListNode*> valMap;

    void bringNodeFront(ListNode* node) {
        if (node->prev) {
            if (node == tail) {
                tail = node->prev;
            }

            node->prev->next = node->next;
            if (node->next) {
                node->next->prev = node->prev;
            }
            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
public:
    LRUCache(int capacity) : 
        head(nullptr), tail(nullptr), capacity(capacity) {
    }
    
    int get(int key) {
        //cerr << "get " << key << endl;
        //cerr << "map size" << valMap.size() << endl;
        if (valMap.contains(key)) {
            ListNode* node = valMap[key];
            bringNodeFront(node);
            return node->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (valMap.contains(key)) {
            ListNode* node = valMap[key];
            node->val = value;
            bringNodeFront(node);
        } else {
            if (valMap.size() >= capacity) {
                // remove the tail first
                ListNode* prevNode = tail->prev;
                cerr << "remove " << tail->key << endl;
                valMap.erase(tail->key);
                delete tail;
                tail = prevNode;
                if (tail) {
                    tail->next = nullptr;
                } else {
                    head = nullptr;
                }
            }
            
            ListNode *newNode = new ListNode(value, key);
            valMap.emplace(key, newNode);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        cerr << "put " << key << "," << value << endl;
    }
};
