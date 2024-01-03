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
        int leftSum = getMaxSum(root->left);
        int rightSum = getMaxSum(root->right);
        cout<<leftSum<<" "<<rightSum<<endl;
        maxi = max({maxi,root->val,root->val+leftSum,root->val+rightSum,leftSum+rightSum+root->val});
        return root->val + max({0,leftSum,rightSum});
    }
    int maxPathSum(TreeNode* root) {
        getMaxSum(root);
        return maxi;
    }
};