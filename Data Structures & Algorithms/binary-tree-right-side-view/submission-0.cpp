/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            if (!node) {
                break;
            }

            // the first node in the queue is the most right node
            res.push_back(node->val);
            int nodeSize = q.size();

            // pop all current level nodes and push all next level nodes
            for (int i = 0; i < nodeSize; i++) {
                node = q.front();
                if (node->right) {
                    q.push(node->right);
                }

                if (node->left) {
                    q.push(node->left);
                }
                q.pop();
            }
        }

        return res;
    }
};
