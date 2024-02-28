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
    void traverse(TreeNode* root,stack<int>& s,int level){
        if(!root) return;
        if(level==s.size()) s.push(root->val);
        traverse(root->left,s,level+1);
        traverse(root->right,s,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        stack<int> s;
        traverse(root,s,0);
        return s.top();
    }
};