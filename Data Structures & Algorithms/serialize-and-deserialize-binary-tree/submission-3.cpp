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
    void serializeHelper(TreeNode* node, vector<string> &vals) {
        if (!node) {
            vals.push_back("N");
            return;
        }

        vals.push_back(to_string(node->val));
        serializeHelper(node->left, vals);
        serializeHelper(node->right, vals);
    }

    TreeNode* deserializeHelper(vector<string> &vals, int &index) {
        if (vals[index] == "N") {
            index++;
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(vals[index++]));
        node->left = deserializeHelper(vals, index);
        node->right = deserializeHelper(vals, index);
        return node;
    }

    string join(vector<string> &vals, string sep) {
        string ret;
        for (auto &val : vals) {
            if (!ret.empty()) {
                ret += sep;
            }
            ret += val;
        }
        return ret;
    }

    void split(string data, char sep, vector<string> &vals) {
        stringstream ss(data);
        string val;
        while(getline(ss, val, sep)) {
            vals.push_back(val);
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> vals;
        serializeHelper(root, vals);
        //cerr << join(vals, ",");
        return join(vals, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        split(data, ',', vals);
        int index = 0;
        return deserializeHelper(vals, index);
    }
};
