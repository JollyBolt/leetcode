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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = getLeftHeight(root->left);
        int rh = getRightHeight(root->right);
        cout<<root->val<<" "<<lh<<" "<<rh<<endl;
        if(rh == lh) return pow(2,rh+1) - 1;
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int getLeftHeight(TreeNode* root){
        if(!root) return 0;
        return 1 + getLeftHeight(root->left); 
    }

    int getRightHeight(TreeNode* root){
        if(!root) return 0;
        return 1 + getRightHeight(root->right); 
    }
};