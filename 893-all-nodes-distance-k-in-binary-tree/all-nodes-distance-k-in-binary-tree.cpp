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
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parents){
        if(!root) return;
        if(root->left) parents[root->left] = root;
        if(root->right) parents[root->right] = root;
        getParents(root->left,parents);
        getParents(root->right,parents);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        vector<int> ans;
        getParents(root,parents);
        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(target);
        // visited[target] = 1;
        while(k>0 and !q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                visited[node] = 1;
                q.pop();
                if(node->left and !visited.count(node->left)) q.push(node->left);
                if(node->right and !visited.count(node->right)) q.push(node->right);
                if(parents.count(node) and !visited.count(parents[node])) q.push(parents[node]);
            }
            k--;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};