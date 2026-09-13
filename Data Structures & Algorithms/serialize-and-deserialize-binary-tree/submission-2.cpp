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

class Codec {
private:
    string serializeHelper(TreeNode* root, int level) {
        if (root == nullptr) {
            return "";
        }
        string finalStr = to_string(root->val);
        if (root->left) {
            finalStr += "," + serializeHelper(root->left, level + 1);
        }

        string sep = "#" + to_string(level) + "#";
        if (root->right) {
            finalStr += sep + serializeHelper(root->right, level + 1);
        }
            
        //cout << finalStr << endl;
        return finalStr;
    }

    TreeNode* deserialize(string data, int level) {
        if (data == "") {
            return nullptr;
        }
        //cout << "level: " << level << " data: " << data << endl;
        auto nextNumber = data.find(',');
        string sep = '#' + to_string(level) + '#';
        auto rightStart = data.find(sep);
        TreeNode *node = new TreeNode();
        if (rightStart == string::npos && nextNumber == string::npos) {
            // only one number in the string
            node->val = stoi(data);
            return node;
        } else if (nextNumber == string::npos) {
            node->val = stoi(data.substr(0, rightStart));
            node->right = deserialize(data.substr(rightStart + sep.size(), 
                data.size() - rightStart - sep.size()), level + 1);
            return node;
        } else if (rightStart == string::npos) {
            node->val = stoi(data.substr(0, nextNumber));
            node->left = deserialize(data.substr(nextNumber + 1, data.size() - nextNumber - 1), level + 1);
            return node;
        } else {
            if (nextNumber < rightStart) {
                node->val = stoi(data.substr(0, nextNumber));
                node->left = deserialize(data.substr(nextNumber + 1, rightStart - nextNumber - 1), level + 1);
                node->right = deserialize(data.substr(rightStart + sep.size(), 
                    data.size() - rightStart - sep.size()), level + 1);
            } else {
                node->val = stoi(data.substr(0, rightStart));
                node->right = deserialize(data.substr(rightStart + sep.size(), 
                    data.size() - rightStart - sep.size()), level + 1);
            }
            return node;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        return serializeHelper(root, 1001);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }

        return deserialize(data, 1001);
    }
};
