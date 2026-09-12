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
    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight,
        vector<int>& inorder, int inLeft, int inRight) {
            if (preLeft > preRight) {
                return nullptr;
            }

            TreeNode *root = new TreeNode(preorder[preLeft]);
            
            int rootVal = preorder[preLeft];
            int leftSize = inValToIndex[rootVal] - inLeft;

            root->left = buildTree(preorder, preLeft + 1, preLeft + leftSize,
                inorder, inLeft, inLeft + leftSize - 1);
            root->right = buildTree(preorder, preLeft + 1 + leftSize, preRight,
                inorder, inLeft + leftSize + 1, inRight);

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

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
