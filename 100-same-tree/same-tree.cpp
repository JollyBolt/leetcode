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
    void check(TreeNode* p, TreeNode* q,bool& flag){
        if(!flag) return;
        if(!p && !q) return;
        else if(!p or !q){
            flag=false;
            return;
        }
        if(p->val==q->val){
            check(p->left,q->left,flag);
            check(p->right,q->right,flag);
        }
        else {
            flag=false;
            return;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(!p or !q) return false;
        if(p->val != q->val) return false;
        return (isSameTree(p->left,q->left) and isSameTree(p->right,q->right));
        // bool flag=true;
        // check(p,q,flag);
        // return flag;
    }
};