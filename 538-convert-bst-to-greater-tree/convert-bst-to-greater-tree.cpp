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
void postOrder(TreeNode* root,int &sum){
        if(!root) return;
        if(root->right) postOrder(root->right,sum);
        sum+=root->val;
        root->val = sum;
        if(root->left) postOrder(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        int sum=0;
        postOrder(root,sum);
        return root;
    }
};