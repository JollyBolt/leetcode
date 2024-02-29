class Solution {
public:
    void solve(int idx,vector<int> temp,int target,vector<int>& candidates, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx == candidates.size()) return;
        int taken;
        if(candidates[idx]>target) return;

        for(int i=idx;i<candidates.size();i++){
            taken = candidates[i];
            temp.push_back(candidates[i]);
            solve(i+1,temp,target-candidates[i],candidates,ans);
            temp.pop_back();
            while(i!=candidates.size()-1 and candidates[i+1]==taken) i++;
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,temp,target,candidates,ans);
        return ans;
    }
};