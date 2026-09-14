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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int res = 0;
        dfs(root,count,res);
        
        return res;
    }

    void dfs(TreeNode* root, int& count, int& res) {
        if(!root) return;
        dfs(root->left,count,res);
        count--;
        if (count == 0) {
            res = root->val;
            return;
        }
        
        dfs(root->right,count,res);
    }
};
