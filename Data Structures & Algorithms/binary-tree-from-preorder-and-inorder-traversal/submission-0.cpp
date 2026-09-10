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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> newPreorder;
        
        int rootVal = preorder[0];
        int leftSize = 0;
        for (int i = 0; inorder[i] != rootVal; i++) {
            leftSize++;
        }
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + leftSize);
        root->left = buildTree(leftPreorder, leftInorder);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> rightInorder(inorder.begin() + leftSize + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};
