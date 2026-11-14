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
    int dfs(TreeNode* node, int p_max) {
        if (!node) return 0;
        int res = 0;
        if (p_max <= node->val) {
            res++;
            p_max = node->val;
        }
        
        res += dfs(node->left,p_max);
        res += dfs(node->right,p_max);

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
