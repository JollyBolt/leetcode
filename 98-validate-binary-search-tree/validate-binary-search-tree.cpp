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
    bool isValid(TreeNode* root,long upper, long lower){
        if(!root) return true;
        // cout<<
        if(root->val<=lower or root->val>=upper) return false;
        bool left = true, right = true;
        if(root->left) left = isValid(root->left,root->val,lower);
        if(root->right) right = isValid(root->right,upper,root->val);

        return left and right;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValid(root->left,root->val,LONG_MIN) and isValid(root->right,LONG_MAX,root->val);
    }
};