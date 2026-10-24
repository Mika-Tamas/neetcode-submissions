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
    int global_max = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return INT_MIN;
        int left = helper(root->left);
        int right = helper(root->right);
        int cur = root->val;

        int path_value;
        if (left < 0 && right < 0) {
            path_value = cur;
        } else if (left < 0) {
            path_value = cur + right;
        } else if (right < 0) {
            path_value = cur + left;
        } else {
            path_value = cur + max(left,right);
            global_max = max(cur + left + right,global_max);
        }
        global_max = max(path_value,global_max);

        return path_value;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return global_max;
    }
};
