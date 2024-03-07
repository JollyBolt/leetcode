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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i = 0;i < inorder.size();i++)  m[inorder[i]] = i;
        int n = postorder.size();
        reverse(postorder.begin(),postorder.end());
        return buildTree(postorder,inorder,0,n-1,0,n-1,m);
    }
    TreeNode* buildTree(vector<int>& postorder,vector<int>& inorder,int postStart,int postEnd,int inStart,int inEnd,map<int,int>& m){
        if(postStart>postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postStart]);
        int index = m[root->val];
        int numsLeft = inEnd - index;
        root->left = buildTree(postorder,inorder,postStart+numsLeft+1,postEnd,inStart,index-1,m);
        root->right = buildTree(postorder,inorder,postStart+1,postStart+numsLeft,index+1,inEnd,m);
        return root;
    }
};