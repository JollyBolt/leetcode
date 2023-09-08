class Solution {
public:
    void solve(int index,int target,vector<int>& v,vector<int>& candidates,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(index==candidates.size()) return;
        
        int i=index;
        while(i<candidates.size()){
            int x=candidates[i];
            if(x<=target){
                v.push_back(x);
                solve(i+1,target-x,v,candidates,ans);
                v.pop_back();
            }
            else return;
            while(i<candidates.size() and candidates[i]==x) i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,target,v,candidates,ans);
        return ans;
    }
};