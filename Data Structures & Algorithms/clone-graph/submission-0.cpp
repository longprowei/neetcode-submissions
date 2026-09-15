/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> visited;
    Node* dfs(Node* node) {
        if (visited.contains(node->val)) {
            return visited[node->val];
        }
        
        Node* newNode = new Node(node->val, node->neighbors);
        visited[node->val] = newNode;
        for (int i = 0; i < newNode->neighbors.size(); i++) {
            newNode->neighbors[i] = dfs(newNode->neighbors[i]);
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        return dfs(node);
    }
};
