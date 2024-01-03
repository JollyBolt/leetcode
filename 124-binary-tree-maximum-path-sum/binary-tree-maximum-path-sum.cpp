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
    int maxi=INT_MIN;

    int getMaxSum(TreeNode* root){
        if(!root) return 0;
        int leftSum = max(0,getMaxSum(root->left));
        int rightSum = max(0,getMaxSum(root->right));
        maxi = max(maxi,leftSum+rightSum+root->val);
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        getMaxSum(root);
        return maxi;
    }
};