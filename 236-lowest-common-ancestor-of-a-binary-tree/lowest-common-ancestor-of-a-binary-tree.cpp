/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode* root, TreeNode* p, TreeNode* q,deque<TreeNode*>& pathA,deque<TreeNode*>& pathB,bool& foundA,bool& foundB){
        if(foundA and foundB) return;
        if(!root) return;
        if(!foundA) pathA.push_back(root);
        if(!foundB) pathB.push_back(root);
        if(root==p) foundA=true;
        if(root==q) foundB=true;
        if(root->left) getPath(root->left,p,q,pathA,pathB,foundA,foundB);
        if(root->right) getPath(root->right,p,q,pathA,pathB,foundA,foundB);
        if(!foundA) pathA.pop_back();
        if(!foundB) pathB.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> pathA,pathB;
        bool foundA=false,foundB=false;
        getPath(root,p,q,pathA,pathB,foundA,foundB);
        TreeNode* lca = root;
        // while(!pathB.empty()){
        //     cout<<pathB.front()->val<<" ";
        //     pathB.pop_front();
        // }
        while(!pathA.empty() and !pathB.empty()){
            // cout<<pathA.front()->val<<" "<<pathB.front()->val<<endl;
            if(pathA.front()==pathB.front()) lca=pathA.front();
            pathA.pop_front();
            pathB.pop_front();
        }
        return lca;
    }
};