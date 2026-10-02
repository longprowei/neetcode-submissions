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
    void dfs(TreeNode* node, int maxValue, int& goodCount) {
        if (!node) {
            return;
        }

        if (node->val >= maxValue) {
            goodCount++;
            maxValue = node->val;
        }
        dfs(node->left, maxValue, goodCount);
        dfs(node->right, maxValue, goodCount);
    }
public:
    int goodNodes(TreeNode* root) {
        int goodCount = 0;
        dfs(root, INT_MIN, goodCount);
        return goodCount;
    }
};
