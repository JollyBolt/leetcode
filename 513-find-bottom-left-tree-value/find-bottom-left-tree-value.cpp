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
    void traverse(TreeNode* root,int& size,int &val,int level){
        if(!root) return;
        if(level==size){
            val = root->val;
            size++;
        } 
        traverse(root->left,size,val,level+1);
        traverse(root->right,size,val,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int val;
        int size=0;
        traverse(root,size,val,0);
        return val;
    }
};