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
    int maxSumValue = numeric_limits<int>::min();

    int maxPathSumRec(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxLeft = maxPathSumRec(root->left);
        int maxRight = maxPathSumRec(root->right);

        maxSumValue = max(
            maxSumValue,
            root->val + max(0, maxLeft) + max(0, maxRight)
        );

        // as we return to parent, so only return use one side, otherwise it won't be a path
        // also should be minimum 0 as well
        return max(0, root->val + max(maxLeft, maxRight));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumRec(root);
        return maxSumValue;
    }
};
