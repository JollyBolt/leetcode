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
    int maxi=0;
    int getHeight(TreeNode* root){
        if(!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        maxi=(max(maxi,lh+rh));
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        getHeight(root);
        return maxi;
    }
};
/*
Time Complexity:O(n)
*/