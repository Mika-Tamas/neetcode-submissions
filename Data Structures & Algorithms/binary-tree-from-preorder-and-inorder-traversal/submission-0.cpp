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
    int i_preorder;
    unordered_map<int,int> index_map;
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int i_mid = index_map[preorder[i_preorder]];
        TreeNode* root = new TreeNode(preorder[i_preorder++]);
        root->left = dfs(preorder,l,i_mid-1);
        root->right = dfs(preorder,i_mid+1,r);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        i_preorder = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            index_map[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size() - 1);
    }
};
