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
private:
    vector<int> values;
    int k;
    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }
        inOrder(node->left);
        values.push_back(node->val);
        if (values.size() == k) {
            return;
        }
        inOrder(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        k = k;
        inOrder(root);
        return values[k - 1];
    }
};
