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
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parents,TreeNode*& target,int start){
        if(!root) return;
        if(root->val == start) target = root;
        if(root->left) parents[root->left] = root;
        if(root->right) parents[root->right] = root;
        getParents(root->left,parents,target,start);
        getParents(root->right,parents,target,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        int time = -1;
        TreeNode* target;
        getParents(root,parents,target,start);
        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                visited[node] = 1;
                q.pop();
                if(node->left and !visited.count(node->left)) q.push(node->left);
                if(node->right and !visited.count(node->right)) q.push(node->right);
                if(parents.count(node) and !visited.count(parents[node])) q.push(parents[node]);
            }
            time++;
        }
        return time;
    }
};