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
    int height(TreeNode* root, bool& res) {
        if (!root) {
            return 0;
        }

        int leftHeight = height(root->left, res);
        int rightHeight = height(root->right, res);
        res = res && (abs(leftHeight - rightHeight) <= 1);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        bool res = true;
        height(root, res);
        return res;
    }
};
