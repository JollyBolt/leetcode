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
                // cout<<((level>>1)&1)<<" ";
                if((level&1)==0){
                    if(((node->val)&1)==0){ //if node->val even
                        if(i==n-1 or i!=n-1 and node->val>q.front()->val){
                            if(node->left) q.push(node->left);
                            if(node->right) q.push(node->right);
                        }
                        else return false;
                    }
                    else return false;
                }
                else{ //Check for odd level
                    if((node->val&1)){ //if node->val odd
                        if(i==n-1 or i!=n-1 and node->val<q.front()->val){
                            if(node->left) q.push(node->left);
                            if(node->right) q.push(node->right);
                        }
                        else return false;
                    }
                    else return false;
                }

            }
            level++;
        }

        return true;
    }
};