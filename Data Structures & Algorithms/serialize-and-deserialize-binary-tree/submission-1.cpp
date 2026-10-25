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

#define DELIMITER ","

class Codec {
    TreeNode* deserializeHelper(string& data, size_t& ind) {
        if (ind >= data.size()) return nullptr;

        size_t new_ind = data.find(DELIMITER, ind);

        string new_val;
        if (new_ind == string::npos) {
            new_val = data.substr(ind);
            ind = data.size();
        } else {
            new_val = data.substr(ind, new_ind - ind);
            ind = new_ind + 1;
        }

        TreeNode* root;
        if (new_val == "N") {
            return nullptr;
        } else {
            root = new TreeNode(stoi(new_val));
        }

        root->left = deserializeHelper(data,ind);
        root->right = deserializeHelper(data,ind);

        return root;
    }

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "N";
        }
        string res = to_string(root->val);
        res = res + DELIMITER + serialize(root->left);
        res = res + DELIMITER + serialize(root->right);

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t ind = 0;
        return deserializeHelper(data, ind);
    }
};
