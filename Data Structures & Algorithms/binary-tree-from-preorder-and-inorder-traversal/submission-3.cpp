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
    unordered_map<int, int> inValToIndex;
    int preOrderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, int inLeft, int inRight) {
            if (inLeft > inRight) {
                return nullptr;
            }

            int rootVal = preorder[preOrderIndex++];
            TreeNode *root = new TreeNode(rootVal);
            int midIndex = inValToIndex[rootVal];

            root->left = buildTree(preorder, inLeft, midIndex - 1);
            root->right = buildTree(preorder, midIndex + 1, inRight);

            return root;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }

        for (int i = 0; i < inorder.size(); i++) {
            inValToIndex[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size() - 1);
    }
};
