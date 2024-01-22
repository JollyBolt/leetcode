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
    int getHeight(TreeNode* root){
        if(!root->left and !root->right) return 1;
        int lh = INT_MAX;
        int rh = INT_MAX;
        if(root->left) lh = 1 + getHeight(root->left);
        if(root->right) rh = 1 + getHeight(root->right);
        return min(rh,lh);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return getHeight(root);
    }
};