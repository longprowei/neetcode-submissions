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
    bool inValidRange(TreeNode* node, int lower, int upper) {
        if (!node) {
            return true;
        }
        //cerr << "val=" << node->val << " lower=" << lower << " upper=" << upper << endl;

        if (node->val <= lower || node->val >= upper) {
            return false;
        }

        return inValidRange(node->left, lower, node->val) &&
            inValidRange(node->right, node->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        int lower = numeric_limits<int>::min();
        int upper = numeric_limits<int>::max();
        return inValidRange(root->left, lower, root->val) &&
            inValidRange(root->right, root->val, upper);
    }
};
