class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> ctp;//child to parent
        for(int i=0;i<n;i++){
            int lc = leftChild[i];
            int rc = rightChild[i];
            if(lc!=-1) {
                if(ctp.count(lc)>0) return false;
                else ctp[lc] = i;
            }
            if(rc!=-1) {
                if(ctp.count(rc)>0) return false;
                else ctp[rc] = i;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(ctp.count(i)==0){
                if(root!=-1) return false;
                else root = i;
            }
        }
        if(root==-1) return false;

        vector<bool> visited(n,false);
        queue<int> q;
        q.push(root);
        // visited[root]=true;
        int count=0;
        while(!q.empty()){
            int len = q.size();
            int node = q.front();
            q.pop();
            if(visited[node]) return false;
            visited[node] = true;
            count++;
            if(leftChild[node]!=-1){
                q.push(leftChild[node]);
            }
            if(rightChild[node]!=-1){
                q.push(rightChild[node]);
            }
        }
        if(count!=n) return false;

        return true;
    }
};