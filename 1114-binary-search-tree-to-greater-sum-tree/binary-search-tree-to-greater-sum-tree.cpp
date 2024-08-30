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
    void reverseInOrder(TreeNode* root,int &sum){
        if(!root) return;
        if(root->right) reverseInOrder(root->right,sum);
        sum+=root->val;
        root->val = sum;
        if(root->left) reverseInOrder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return nullptr;
        int sum=0;
        reverseInOrder(root,sum);
        return root;
    }
};