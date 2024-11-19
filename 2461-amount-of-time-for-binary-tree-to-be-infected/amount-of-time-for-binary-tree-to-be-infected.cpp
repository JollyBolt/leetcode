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
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,int start,TreeNode*& target){
        if(!root) return;
        if(root->val==start) target = root;
        if(root->left){
            m[root->left] = root;
            getParents(root->left,m,start,target);
        }
        if(root->right){
            m[root->right] = root;
            getParents(root->right,m,start,target);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> m;
        TreeNode* target;
        getParents(root,m,start,target);
        unordered_map<TreeNode*,int> burned;
        int ans=0;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int n = q.size();
            ans++;
            while(n--){
                TreeNode *node = q.front();
                q.pop();
                burned[node]++;
                if(node->left and burned.count(node->left)==0) q.push(node->left);
                if(node->right and burned.count(node->right)==0) q.push(node->right);
                if(m[node] and burned.count(m[node])==0) q.push(m[node]);
            }
        }
        return ans-1;
    }
};