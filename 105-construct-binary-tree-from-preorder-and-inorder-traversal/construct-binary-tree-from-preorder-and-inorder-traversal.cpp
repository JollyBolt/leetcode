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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i = 0;i < inorder.size();i++)  m[inorder[i]] = i;
        int n = preorder.size();
        return buildTree(preorder,inorder,0,n-1,0,n-1,m);
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>& m){
        if(preStart>preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = m[root->val];
        int numsLeft = index-inStart;
        root->left = buildTree(preorder,inorder,preStart+1,preStart+numsLeft,inStart,index-1,m);
        root->right = buildTree(preorder,inorder,preStart+numsLeft+1,preEnd,index+1,inEnd,m);
        return root;
    }
};