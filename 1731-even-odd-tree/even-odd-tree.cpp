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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++ ){
                TreeNode *node = q.front();
                q.pop();
                //Check for even level
                if(((level&1)==0) and (((node->val)&1) or (i!=n-1 and node->val<=q.front()->val))) return false;
                //Check for odd level
                if((level&1) and (((node->val)&1)==0 or (i!=n-1 and node->val>=q.front()->val))) return false;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            level++;
        }
        return true;
    }
};