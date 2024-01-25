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
    void util(TreeNode* root,int len,int odd,int& ans,unordered_map<int,int> v){
        v[root->val]++;
        if(v[root->val]%2!=0) odd++;
        else odd--;
        if(!root->left and !root->right) {
            if((odd==1 and len%2!=0) or odd==0) ans++;
            return;
        }
        if(root->left) util(root->left,len+1,odd,ans,v);
        if(root->right) util(root->right,len+1,odd,ans,v);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> m;
        int odd=0;
        int ans=0;
        int len=0;
        util(root,1,odd,ans,m);
        return ans;
    }
};